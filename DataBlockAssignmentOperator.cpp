#include <iostream>
#include "Matrix.h"

int main()
{

    // Test Assignment Operator(from a non-empty object)
    // {
    //     DataBlock d1 = "1 2 3; 4 5 6";
    //     DataBlock d2 = "1 2; 3 4; 5 6";
    //     std::cout << "Before Copying, d1: " << std::endl;
    //     std::cout << d1;
    //     std::cout << "Before Copying, d2: " << std::endl;
    //     std::cout << d2;
    //     d1 = d2;
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

    // Test Assignment Operator(from a empty object)
    {
        DataBlock d1 = "1 2 3; 4 5 6";
        DataBlock d2;
        std::cout << "Before Copying, d1: " << std::endl;
        std::cout << d1;
        std::cout << "Before Copying, d2: " << std::endl;
        std::cout << d2;
        d1 = d2;
        std::cout << "After Copying, d1: " << std::endl;
        std::cout << d1;
        std::cout << "After Copying, d2: " << std::endl;
        std::cout << d2;

        // d1.resetI();

        // std::cout << "After Reset d1, d1: " << std::endl;
        // std::cout << d1;
        // std::cout << "After Reset d1, d2: " << std::endl;
        // std::cout << d2;
    }

    // Test Move Assignment Operator(from a non-empty object)
    // {
    //     DataBlock d1 = "1 2 3; 4 5 6";
    //     DataBlock d2 = "1 2; 3 4; 5 6";
    //     std::cout << "Before Copying, d1: " << std::endl;
    //     std::cout << d1;
    //     std::cout << "Before Copying, d2: " << std::endl;
    //     std::cout << d2;
    //     d1 = std::move(d2);
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

    // Test Move Assignment Operator(from an empty object)
    // {
    //     DataBlock d1 = "1 2 3; 4 5 6";
    //     DataBlock d2;
    //     std::cout << "Before Copying, d1: " << std::endl;
    //     std::cout << d1;
    //     std::cout << "Before Copying, d2: " << std::endl;
    //     std::cout << d2;
    //     d1 = std::move(d2);
    //     std::cout << "After Copying, d1: " << std::endl;
    //     std::cout << d1;
    //     std::cout << "After Copying, d2: " << std::endl;
    //     std::cout << d2;

    //     // d1.resetI();

    //     // std::cout << "After Reset d1, d1: " << std::endl;
    //     // std::cout << d1;
    //     // std::cout << "After Reset d1, d2: " << std::endl;
    //     // std::cout << d2;
    // }

    std::cin.get();

    return 0;
}
