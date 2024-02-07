#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void)
{
    string fnamedeclare = "First Name: ";
    string lnamedeclare = "Last Name: ";
    string agedeclare = "Age: ";
    string heightdeclare = "Height in Feet: ";


    string fname = "Hayden";
    string lname = "Armstrong";
    int age = 18;
    double height = 6.545234;

    string fname2 = "Alpho";
    string lname2 = "Bent";
    int age2 = 24;
    double height2 = 5.59;

    //cout << showpoint << height << endl;
    cout << setw(15) << left << fnamedeclare;
    cout << setw(15) << left << lnamedeclare;
    cout << setw(5) << agedeclare;
    cout << setw(5) << heightdeclare << endl;

    cout << setw(15) << left << fname;
    cout << setw(15) << left << lname;
    cout << setw(5) << age;
    cout << setw(5) << setprecision(3) << height << endl;

    cout << setw(15) << left << fname2;
    cout << setw(15) << left << lname2;
    cout << setw(5) << age2;
    cout << setw(5) << setprecision(3) << height2 << endl;
     cout << setw(10)<< "" << "-------Math Operations-------" << endl;;

    cout << "2 to the 3rd power = " << pow(2,3) << endl;
    cout << "sin(pi) = " << sin(M_PI) << endl;

    return 0;
}