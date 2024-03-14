#include <iostream>

using namespace std;

//stack - 1-4mb of automaticall given memory
//heap - ram you ask OS for
int main(void)
{
    int values[5] = {0, 1, 2, 3, 4}; // values are not initializeed
    int values2[5] = {0,0,0,0,0};//initialized array

    char name[260] = "Hayden";

    cout << "sizeof(values) = " << sizeof(values) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;

    for(int i=0; i<sizeof(values)/sizeof(int); i++)
    // for i from 0 to sizeof whole array divided by size of type of 
    {
        cout << values[i] << ' ';

    }
    cout << endl;

    for(auto i: values) // can use auto if dont know the type, but it's kind of sloppy
    {
        cout << i << ' ';
    }
    name[0] = 'j'; // changes first letter to L
    cout << endl;
    cout << name << endl;
    return 0;

}