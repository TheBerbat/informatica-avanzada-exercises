#include <iostream>

class Overflow{
    float a_{}, b_{};
public:
    explicit Overflow(float a, float b)
      : a_{a}
      , b_{b}
    {
        std::cout << "Created exception: Overflow\n";
    }

    std::string msg() const {
        return "Overflow a=" + std::to_string(a_) + ", b=" + std::to_string(b_);
    }
};

float division(float a, float b)
{
    if(b==0)
        throw "division by zero";
    if(a>1000.0f && b<0.01f)
        throw Overflow(a,b);
    return a/b;
}

int main()
{
    try {
        division(10000.0f,0.0001);
    }
    catch(char const *t) { 
        std::cerr << t << std::endl;
    }
    catch (const Overflow& d) {
        std::cout << "Exception catch, msg: ";
        std::cout << d.msg() << '\n';
    } 
}
