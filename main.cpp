#include <iostream>
#include <vector>

class InitExample
{
private:
    std::vector<int> vArray{10,20,30,40,50};
public:
    InitExample() = default;

    InitExample(std::initializer_list<int> list)
    {
        vArray = list;
    }

    ~InitExample()
    {
        vArray.clear();
        std::cout << "Deleting" << std::endl;
        std::cout << "array size is: " << vArray.size() << std::endl;
    }

    void print()
    {
        for(auto i : vArray)
        {
            std::cout << i << " * ";
        }
        std::cout << std::endl;
    }
};

int main() {
    //ini default
    auto* a = new InitExample();
    a->print();
    delete a;
    //initializer aggregate
    auto* b = new InitExample({1,2,3,4,5});
    b->print();
    delete b;
    return 0;
}
