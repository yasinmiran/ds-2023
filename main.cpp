
#include <iostream>

// int main(int argc, char **argv)
// {
//     std::cout << "Hello World" << std::endl;
//     return 0;
// }

// g++ ./main.cpp -o main
int main(int argc, char **argv)
{
    int a = 6;
    int &ra = a;
    int *c = &a;

    std::cout << a << std::endl;
    std::cout << ra << std::endl;
    std::cout << &ra << std::endl;
    std::cout << &a << std::endl;
    std::cout << &c << std::endl;

    return 0;
}