#include <iostream>
#include "Matrix.h"

int main()
{
    // Test Default Constructor
    // {
    //     DataBlock d1;
    //     std::cout << d1;
    // }

    // Test Constructor
    // {
    //     DataBlock d1 = "1 2 3; 4 5 6";
    //     std::cout << d1;
    // }

    // Test Copy Constructor(from an empty object)
    // {
    //     DataBlock d1;
    //     DataBlock d2 = d1;
    //     std::cout << "After Copying, d1: " << std::endl;
    //     std::cout << d1;
    //     std::cout << "After Copying, d2: " << std::endl;
    //     std::cout << d2;
    // }

    // Test Copy Constructor(from an non-empty object)
    // {
    //     DataBlock d1 = "1 2 3; 4 5 6";
    //     DataBlock d2 = d1;
    //     std::cout << "After Copying, d1: " << std::endl;
    //     std::cout << d1;
    //     std::cout << "After Copying, d2: " << std::endl;
    //     std::cout << d2;

    //     d1.resetI();

    //     std::cout << "After Reset d1, d1: " << std::endl;
    //     std::cout << d1;
    //     std::cout << "After Reset d1, d2: " << std::endl;
    //     std::cout << d2;
    // }

    // Test Move Constructor
    {
        DataBlock d1 = "1 2 3; 4 5 6";
        DataBlock d2 = std::move(d1);
        std::cout << "After Moving, d1: " << std::endl;
        std::cout << d1;
        std::cout << "After Moving, d2: " << std::endl;
        std::cout << d2;
    }

    // Test Move Constructor(from an empty obj)
    // {
    //     DataBlock d1;
    //     DataBlock d2 = std::move(d1);
    //     std::cout << "After Moving, d1: " << std::endl;
    //     std::cout << d1;
    //     std::cout << "After Moving, d2: " << std::endl;
    //     std::cout << d2;
    // }

    std::cin.get();

    return 0;
}
