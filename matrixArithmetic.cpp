#include <iostream>
#include "Matrix.h"

int main()
{
    // {
    //     Matrix m1 = " 8 1 6; 3 5 7; 4 9 2";
    //     std::cout << m1;

    //     Matrix m2 = m1 + 10;
    //     std::cout << m2;

    //     m2 = m1 - 10;
    //     std::cout << m2;

    //     m2 = m1 * 10;
    //     std::cout << m2;

    //     m2 = m1 / 10;
    //     std::cout << m2;
    // }

    // {
    //     Matrix m1 = " 8 1 6; 3 5 7; 4 9 2";
    //     std::cout << m1;

    //     Matrix m2 = m1 + 10;
    //     std::cout << m2;

    //     m2 = m2 - 10;
    //     std::cout << m2;

    //     m2 = m2 * 10;
    //     std::cout << m2;

    //     m2 = m2 / 10;
    //     std::cout << m2;
    // }

    // {
    //     Matrix m1 = " 8 1 6; 3 5 7; 4 9 2";
    //     std::cout << m1;

    //     m1.t();
    //     std::cout << m1;

    //     m1.lu();
    //     std::cout << m1;

    //     m1.rref();
    //     std::cout << m1;

    //     m1 = m1 + 1;
    //     std::cout << m1;
    // }

    // {
    //     Matrix m1 = " 8 1 6; 3 5 7; 4 9 2";
    //     std::cout << m1;

    //     Matrix m2 = DataBlock::eye(3);
    //     std::cout << m2;

    //     Matrix m3 = m1 + m2;
    //     std::cout << m3;

    //     m3 = m1 - m2;
    //     std::cout << m3;
    // }

    {
        Matrix m1 = " 1 2 3; 4 5 6";
        std::cout << m1;

        Matrix m2 = " 1 2; 3 4; 5 6";
        std::cout << m2;

        Matrix m3 = m1 * m2;
        std::cout << m3;

        m3 = m2 * m1;
        std::cout << m3;
    }

    std::cin.get();

    return 0;
}