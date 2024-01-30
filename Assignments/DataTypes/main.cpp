/* 
Hayden Armstrong
1/29/24
Examples of sizeof() functions and data types
*/
#include <iostream>
#include <cmath> //allows us to do exponential operation in c++
using namespace std;

int main(void)
{
    cout << "bool size: " << sizeof(bool) << endl;
    cout << "Char size: " << sizeof(char) << endl;
    cout << "Int size: " << sizeof(int) << endl;
    cout << "Float size: " << sizeof(float) << endl;
    cout << "Long size: " << sizeof(long) << endl;
    cout << "Double size: " << sizeof(double) << endl;
    cout << "2^8 - 1: " << pow(2,8)-1 << endl; //exponent sign "^" does not perform exponent operation in c++. we can use pow(x) instead
    cout << 15*16+8 << endl;
    /*
    15 to base-2
    15/2 = 7 +(remainder of 1)
    7/2 = 3 +(remainder of 1)
    3/2 = 1 +(remainder of 1)
    = 1111
    */
    return 0;
}