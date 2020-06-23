#include <iostream>
#include "Matrix.h"

int main()
{
    // Test Copy Assignment Operator(from an non-empty object)
    // {
    //     Matrix m1;
    //     Matrix m2 = "1 2 3; 4 5 6";
    //     m1 = m2;
    //     std::cout << m1;
    //     std::cout << m2;
    // }

    // Test Copy Assignment Operator(from an empty object)
    // {
    //     Matrix m1 = "1 2 3; 4 5 6";
    //     Matrix m2;
    //     m1 = m2;
    //     std::cout << m1;
    //     std::cout << m2;
    // }

    // Test Move Assignment Operator(from an non-empty object)
    // {
    //     Matrix m1;
    //     Matrix m2 = "1 2 3; 4 5 6";
    //     m1 = std::move(m2);
    //     std::cout << m1;
    //     std::cout << m2;
    // }

    // Test Move Assignment Operator(from an empty object)
    {
        Matrix m1 = "1 2 3; 4 5 6";
        Matrix m2;
        m1 = std::move(m2);
        std::cout << m1;
        std::cout << m2;
    }

    std::cin.get();

    return 0;
}