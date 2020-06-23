#include <iostream>
#include "Matrix.h"

int main()
{
    // {
    //     Matrix m1 = "2 5 8 7; 5 2 2 8; 7 5 6 6 ;5 4 4 8";
    //     std::cout << m1;

    //     m1.lu();
    //     std::cout << m1;
    // }

    // {
    //     Matrix m1 = "8 1 6 1; 3 5 7 1; 4 9 2 1";
    //     std::cout << m1;

    //     m1.lu();
    //     std::cout << m1;
    // }
    {
        Matrix m1 = " 16 2 3 13 ; 5 11 10 8; 9 7 6 12 ; 4 14 15 1";
        std::cout << m1;

        m1.lu();
        std::cout << m1;
    }

    std::cin.get();

    return 0;
}