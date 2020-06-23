#include <iostream>
#include "Matrix.h"

int main()
{
    // Test Default Constructor
    // {
    //     Matrix m1;
    //     std::cout << m1;
    // }

    // Test Constructor
    // {
    //     Matrix m1 = "1 2 3; 4 5 6";
    //     std::cout << m1;
    // }

    // Test Copy Constructor
    // {
    //     // from a DataBlock obj
    //     DataBlock d1 = "1 2 3; 4 5 6";
    //     Matrix m1 = d1;
    //     std::cout << m1;

    //     // from a Matrix obj
    //     Matrix m2 = m1;
    //     std::cout << m2;
    // }

    // Test Move Constructor
    {
        Matrix m1 = "1 2 3; 4 5 6";
        Matrix m2 = std::move(m1);
        std::cout << "After Moving, m1: " << std::endl;
        std::cout << m1;
        std::cout << "After Moving, m2: " << std::endl;
        std::cout << m2;
    }
    std::cin.get();

    return 0;
}