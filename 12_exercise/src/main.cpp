#include <iostream>

#include <graph.hpp>

int main()
{
    uclm::graph<int> g;

    g.create_node(0);
    g.create_node(1);
    g.create_node(2);
    g.create_node(3);
    g.create_node(4);
    g.create_node(5);
    g.create_node(6);
    g.create_node(7);
    g.create_node(8);
    g.create_node(35);

    g.make_adjacent(g[1], g[2]);
    g.make_adjacent(g[1], g[3]);
    g.make_adjacent(g[1], g[4]);
    
    g.make_adjacent(g[3], g[5]);
    
    g.make_adjacent(g[4], g[3]);

    g.make_adjacent(g[2], g[6]);
    g.make_adjacent(g[6], g[8]);

    g.make_adjacent(g[3], g[5]);
    g.make_adjacent(g[5], g[7]);

    std::cout << "> CHECK IF CAN WORK WITH CONST NODES:\n";
    const uclm::graph<int>::node& h = g[1];
    std::cout << h[1].get() << "\n";
    std::cout << h.is_adjacent(g[2]) << "\n";

    std::cout << "> CHECK IF TWO NODES ARE ADJACENTS:\n";
    std::cout << g[1].is_adjacent(g[2]) << '\n';

    std::cout << "> PRINT SEARCH WITH DFS:\n";
    uclm::graph<int>::node* e1 = g.search_DFS(8);
    std::cout << e1->get() << "\n";

    std::cout << "> PRINT SEARCH WITH BFS:\n";
    uclm::graph<int>::node* e2 = g.search_BFS(35);
    std::cout << e2->get() << "\n";

    std::cout << "> PRINT ALL NODES (WITH ADJACENTS):\n";
    g.print_nodes();

    return 0;
}