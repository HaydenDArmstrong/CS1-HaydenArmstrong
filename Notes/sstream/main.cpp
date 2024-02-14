#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main (void)
{
    string fname, lname, phrase;
    int age;

    cout << "Enter full name and age" << endl;

   // cin >> fname >> lname >> age;
    getline (cin, phrase); // now we have 'phrase', which is all given input combined. How do we split it up? with stringstream

    istringstream iss(phrase); 
    // Create an input string stream varible (which will act like a special cin). pass the phrase string in to process

    iss >> fname >> lname >> age;

    cout << "Hello " << fname << ' ' << lname <<
    ", it says here you are " << age << " years old." << endl;

    //iomanip setfill; makes the entire line a specific character
    cout << setw(42) << setfill('=') << ' ' << endl;
    cout << setfill('-') << setw(15) << left << fname << setw(20) << left << lname << setw(5) << left << age << endl;
    cout << setw(42) << setfill('=') << ' ' << endl;

    //cstdio print out function. %s=string %d= integer %f=float. then you put in parameters afterward
    printf ("Hello %s, nice to meet you. Says here you are %d years old.", fname.c_str(), age); // c string is different from c++ string. we convert using .c_str()
    return 0;
}