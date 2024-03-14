#include <iostream>

using namespace std;

int main(void)
{
    int values[100] = {0,1,2,3,4,5};

    int *point_to_int; // declaring a pointer which is just a variable that stores an address

    cout << "Address of values is at: " << values << endl;
    cout << "Address of values[1] is at: " << &values[1] << endl;

    cout << "Size of int = " << sizeof(int) << endl;

    cout << "Value of pointer to int " << point_to_int << endl;

    point_to_int = values+1; // pointer arithmetic, addes the number times sizeof(type)

    cout << point_to_int[1] << endl;
    cout << values[1] << endl;

    return 0;

}