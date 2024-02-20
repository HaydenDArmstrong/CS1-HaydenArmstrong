#include <iostream>

int main(void)
{
    int value = 0;
    int negvalue = 0;

    //positive/additive operators

    //post increment
    std::cout << "value = " << value << std::endl;
    std::cout << "value++ = " << value++ << std::endl;
    std::cout << "value ++ ++ = " << value++ << std::endl;

    std::cout << "Value after post increment operations = " << value << std::endl;

    //pre increment
    std::cout << "++ value  = " << ++value << std::endl;
    std::cout << "++ ++ value = " << ++value << std::endl;

    std::cout << "Value after Pre increment and post increment operations = " << value << std::endl;


    std::cout << " " << std::endl;

    // negative operators

    //post increment
    std::cout << "negvalue = " << negvalue << std::endl;
    std::cout << "negvalue-- = " << negvalue-- << std::endl;
    std::cout << "negvalue -- --  = " << negvalue-- << std::endl;

    std::cout << "negValue after post increment operations = " << negvalue << std::endl;

    //pre increment
    std::cout << "-- negvalue  = " << --negvalue << std::endl;
    std::cout << "-- -- negvalue = " << --negvalue << std::endl;

    std::cout << "negValue after Pre increment and post increment operations = " << negvalue << std::endl;
}