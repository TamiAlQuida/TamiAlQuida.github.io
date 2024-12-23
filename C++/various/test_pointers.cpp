#include <iostream>

int x = 5;
int y = 12;
int* ptr = &x;


int main() {
    std::cout << "Value of x = " << x << std::endl;
    std::cout << "Adress of c = " << &x << std::endl;
    std::cout << "value of ptr = " << *ptr << std::endl;
    std::cout << "Adress of ptr = " << ptr << std::endl;

    *ptr = 6;

    std::cout << "Value of x = " << x << std::endl;

    x = 7;

    std::cout << "value of ptr = " << *ptr << std::endl;

    ptr = &y;

    std::cout << *ptr;
}