#include <iostream>
#include "Matrix.h"

int main()
{
    // {
    //     Matrix m1 = " 8 1 6; 3 5 7; 4 9 2";
    //     std::cout << m1;

    //     m1.rref();
    //     std::cout << m1;
    // }

    {
        Matrix m1 = " 16 2 3 13 ; 5 11 10 8; 9 7 6 12 ; 4 14 15 1";
        std::cout << m1;

        m1.rref();
        std::cout << m1;
    }

    // {
    //     Matrix m1 = "8 1 6 1; 3 5 7 1; 4 9 2 1";
    //     std::cout << m1;

    //     m1.rref();
    //     std::cout << m1;
    // }

    // {
    //     Matrix m1 = "8 1 6 1 0 0; 3 5 7 0 1 0; 4 9 2 0 0 1";
    //     std::cout << m1;

    //     m1.rref();
    //     std::cout << m1;
    // }

    // {
    //     Matrix m1 = "1 1 5 6; 2 1 8 8 ; 1 2 7 10; -1 1 -1 2";
    //     std::cout << m1;

    //     m1.rref();
    //     std::cout << m1;
    // }

    std::cin.get();

    return 0;
}