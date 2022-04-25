#pragma once
#include <memory>
#include <list>
#include <queue>
#include <optional>

namespace uclm
{

template <typename T>
struct graph
{
    struct node;
    struct adjacent
    {
        node& begin;
        node& end;

        adjacent(node& begin, node& end)
          : begin {begin}
          , end {end}
        {}
    };
    struct node
    {
        node(graph* super)
          : node{super, {}}
        {}

        node(graph* super, T data)
          : super_{super}
          , visited {false}
          , data {data}
          , adjacents_{}
        {}

        // NODES CANNOT BE COPIED OR MOVED, THEN DISABLES
            node(const node& other) = delete;
            node& operator=(const node& other) = delete;
            node(node&& other) = delete;
            node& operator=(node&& other) = delete;

        void insert_adjacent(adjacent* adj)
            { adjacents_.push_back(adj); }
            
        void make_adjacent(node& n)
            { super_->make_adjacent(*this, n); }

        bool is_adjacent(const node& other) const
        {
            for(const auto& e : adjacents_)
                if(&e->end == &other)
                    return true;
            return false;
        }

        void clear_search()
            { visited = false; }

        node* search_DFS(const T& data_search)
        {
            if (visited)
                return nullptr;
            visited = true;
            //std::cout << "VISITED " << data << "(" << this << ")\n";

            if (data_search == data)
                return this;
                
            for(auto e : adjacents_)
            {   
                auto result = e->end.search_DFS(data_search);
                if (result != nullptr)
                    return result;
            }   
            return nullptr;
        }

        node* search_BFS(const T& data_search)
        {
            std::queue<node*> node_queue;
            node_queue.push(this);
            return search_BFS_(data_search, node_queue);
        }

        node* search_BFS_(const T& data_search, std::queue<node*>& node_queue)
        {
            node_queue.pop();
            if (visited)
                return nullptr;
            visited = true;
            //std::cout << "VISITED " << data << "(" << this << ")\n";

            if (data_search == data)
                return this;
                
            for(graph::adjacent* e : adjacents_)
            {
                node_queue.push(&(e->end));
            }
            node* next_node = node_queue.front();
            if (next_node)
                return next_node->search_BFS_(data_search, node_queue);
            return nullptr;
        }

        T& get() { return data; }
        const T& get() const { return data; }

        node& operator[](std::size_t n) {
            typename std::list<graph<T>::adjacent*>::iterator it {adjacents_.begin()};
            std::advance(it, n);
            return (*it)->end;
        }
        const node& operator[](std::size_t i) const
        {
            return (const_cast<node*>(this))->operator[](i);
        }

        void print_all()
        {
            std::cout << data << ": ";
            for (adjacent* i : adjacents_)
                std::cout << i->end.data << " ";
            std::cout << '\n';
        }

    private:
        graph* super_ {};
        bool visited {false};
        T data {};
        std::list<adjacent*> adjacents_ {};
    };

    node& create_node(T data)
        { return node_list_.emplace_back(this, data); }

    void make_adjacent(node& begin, node& end, bool is_one_way = false)
    {
        if(begin.is_adjacent(end))
            return;

        adjacent& n_adjacent = adjacent_list_.emplace_back(begin, end);
        begin.insert_adjacent(&n_adjacent);
            
        if (!is_one_way)
            make_adjacent(end, begin, false);
    }

    node* search_DFS(const T& data)
    {
        clear_search();
        for (node& e: node_list_)
        {
            node* res = e.search_DFS(data);
            if (res != nullptr)
                return res;
        }
        return nullptr;
    }

    node* search_BFS(const T& data)
    {
        clear_search();
        for (node& e: node_list_)
        {
            node* res = e.search_BFS(data);
            if (res != nullptr)
                return res;
        }
        return nullptr;
    }

    void print_nodes()
    {
        for (node& elem : node_list_)
            elem.print_all();
    }

    node& operator[](std::size_t n) {
        auto it {node_list_.begin()};
        std::advance(it, n);
        return *it;
    }
    const node& operator[](std::size_t i) const
    { return (const_cast<graph*>(this))->operator[](i); }

private:
    void clear_search()
    {
        for (auto& e: node_list_)
            e.clear_search();
    }

    std::list<node>     node_list_;
    std::list<adjacent> adjacent_list_;
};

} // namespace uclm
