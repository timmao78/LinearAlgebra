#include <iostream>
#include "Matrix.h"

int main()
{

    // {
    //     DataBlock d1 = "1 2 3; 4 5 6";
    //     std::cout << d1;
    //     DataBlock d2 = d1.t();
    //     std::cout << d1;
    //     std::cout << d2;
    // }

    {
        Matrix m1 = "1 2 3; 4 5 6";
        std::cout << m1;
        m1.t();
        std::cout << m1;
    }

    std::cin.get();

    return 0;
}
