#include <iostream>
#include "Matrix.h"

int main()
{

    // {
    //     std::cout << DataBlock::eye(5);
    // }

    // {
    //     DataBlock d1 = DataBlock::eye(5);
    //     std::cout << d1;
    // }

    {
        DataBlock d1 = std::move(DataBlock::eye(5));
        std::cout << d1;
    }

    std::cin.get();

    return 0;
}
