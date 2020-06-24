#include <iostream>
#include "Matrix.h"

int main()
{

    // temporary object
    // std::cout << DataBlock("1 2 3");

    // // constructor
    // {
    //     DataBlock d1 = "1 2 3";
    // }

    // copy constructor
    // {
    //     DataBlock d1 = "1 2 3";
    //     DataBlock d2 = d1;
    // }

    // move constructor
    // {
    //     DataBlock d1 = "1 2 3";
    //     DataBlock d2 = std::move(d1);
    // }

    // {
    //     DataBlock d1 = std::move(DataBlock::eye(3));
    //     std::cout << d1;
    // }

    {
        DataBlock d1 = DataBlock::eye(3);
        d1 = DataBlock::eye(4);
        d1 = DataBlock::eye(5);
        DataBlock::freeTemp();
        std::cout << d1;
    }
    std::cin.get();

    return 0;
}
