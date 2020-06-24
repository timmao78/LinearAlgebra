#include <iostream>
#include "Matrix.h"

int main()
{
    int j = 10;
    for (int i = 0; i< 5; i++)
    {
        std::cout << j << std::endl;
        int j = i;
        std::cout << j << std::endl;
    }

    std::cin.get();
    return 0;
}
