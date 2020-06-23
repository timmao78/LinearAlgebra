#include <iostream>
#include "Matrix.h"

int main()
{
    // {
    //     DataBlock d1 = " 8 1 6; 3 5 7; 4 9 2";
    //     std::cout << d1;

    //     DataBlock d2 = d1 + 10;
    //     std::cout << d2;

    //     d2 = d1 - 10;
    //     std::cout << d2;

    //     d2 = d1 * 10;
    //     std::cout << d2;

    //     d2 = d1 / 10;
    //     std::cout << d2;
    // }

    // {
    //     DataBlock d1 = " 8 1 6; 3 5 7; 4 9 2";
    //     std::cout << d1;

    //     DataBlock d2 = d1 + 10;
    //     std::cout << d2;

    //     d2 = d2 - 10;
    //     std::cout << d2;

    //     d2 = d2 * 10;
    //     std::cout << d2;

    //     d2 = d2 / 10;
    //     std::cout << d2;
    // }

    // {
    //     DataBlock d1 = " 8 1 6; 3 5 7; 4 9 2";
    //     std::cout << d1;

    //     DataBlock d2 = DataBlock::eye(3);
    //     std::cout << d2;

    //     DataBlock d3 = d1 + d2;
    //     std::cout << d3;

    //     d3 = d1 - d2;
    //     std::cout << d3;
    // }

    {
        DataBlock d1 = " 1 2 3; 4 5 6";
        std::cout << d1;

        DataBlock d2 = "1 2; 3 4; 5 6";
        std::cout << d2;

        DataBlock d3 = d1 * d2;
        std::cout << d3;

        d3 = d2 * d1;
        std::cout << d3;

    }

    std::cin.get();

    return 0;
}