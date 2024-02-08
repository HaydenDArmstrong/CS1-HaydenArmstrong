/*
Library Functions Lab
Updated By: Hayden Armstrong
CSCI 111
Date: 2/8/24

Program prompts user to enter a decimal number. It then finds various trig and mathematical values 
of the number using library functions and prints the results using cstdio's printf function.

Algorithm:
    1. Prompt user to enter a decmial number
    2. Store the number into a variable
    3. Find and print various results form the number
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <cmath> // various math functions: https://cplusplus.com/reference/cmath
using namespace std;

int main()
{
    double number, result;

    cout << "Program calculates various results from a given number" << endl;
    cout << "Enter a decimal number: ";
    cin >> number;
    // Find ceiling of the number
    result = ceil(number);
    printf("ceiling(%f) = %.1f\n", number, result);
    // Find floor of the number
    result = floor(number);
    printf("Floor(%f) = %.1f\n", number, result);

    //FIXME3 - Using library function, find and print the square root of the number upto 2 decimal points
    result =  pow(number, 2); //sqrt
    printf("Square Root(%f) = %.2f\n", number, result);

    //FIXME4 - Using library function, find and print the cube root of the number upto 2 decimal points
    result =  pow(number, 3); //cbrt
    printf("Cubed Root(%f) = %.2f\n", number, result);

    //FIXME5 - Using library function, find and print the 10th power of the number upto 2 decimal points
    result = pow(number, 10);
    printf("10th power(%f) = %.2f\n", number, result);

    //FIXME6 - Using library function, find and print the log_2 of the number upto 2 decimal points
    result = log2(number);
    printf("log_2(%f) = %.2f\n", number, result);

    //FIXME7 - Using library function, find and print the log_10 of the number upto 2 decimal points
    result = log10(number);
    printf("log_10(%f) = %.2f\n", number, result);

    //FIXME8 - Convert number into radians and store into a variable
    double radianResult = number * M_PI/180.0;
    printf("radians(%F) = %.2F\n", number, radianResult); 

    //FIXME9 - Using library function, find and print the sine of the radian value in FIXME 8 upto 2 decimal points
    double sineResult = sin(radianResult);
    printf("Sine of Radian Value(%F) = %.2F\n", number, sineResult); 

    //FIXME10 - Using library function, find and print the cosine of the radian value in FIXME 8 upto 2 decimal points
    double cosineResult = cos(radianResult);
    printf("Cosine of Radian Value(%F) = %.2F\n", number, cosineResult); 

    cin.ignore(1000, '\n');
    cout << "Enter to quit the program: ";
    cin.get();
    cout << "Good bye..." << endl;
    return 0;
}
