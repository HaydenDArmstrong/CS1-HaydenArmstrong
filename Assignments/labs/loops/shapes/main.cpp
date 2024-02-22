/*
    Loops Lab
    Updated By: Hayden Armstrong
    CSCI 111
    Date: 2/22/2024

    Program prints geometric shapes of given height with * using loops
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printTriangle(int height) // prints inital triangle with height input
{
    //Function takes height as an argument to print the triangle
    //of that height with *
    int row = 1;
    // row
    while (row <= height) {
        // column
        for(int col = 1; col<=row; col++)
            cout << "* ";
        row += 1;
        cout << endl;
    }
}


void printFlippedTriangle(int height)  // prints flipped triangle with height input
{

     for (int row = height; row >= 1; row--) 
     {
        for (int col = 1; col <= row; col++)
            cout << "* ";
        cout << endl;
    }
}


void printSquare(int height) // prints square with height input
{

    for (int row = 1; row <= height; row++) 
    {
        for (int col = 1; col <= height; col++) 
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// function clears the screen system call
// NOTE: system call is not a security best pracice!
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

int main(int argc, char* argv[]) 
{

    string userAnswer = "y"; //user answer is set to default as y so this program can run on first round

    while (userAnswer == "y" || userAnswer == "Y")
    {
        int height;
        cout << "Program prints geometric shapes of given height with *\n";
        cout << "Please enter the height of the shape: ";
        cin >> height;
        // call printTriangle function passing user entered height
        printTriangle(height);

    
        // Call printFlippedTriangle
        printFlippedTriangle(height);

        // Call printsquare
        printSquare(height);

        // prompt user to enter y/Y to continue anything else to quit
        cout << "Do you wish to continue? (y/n)" << endl;
        cin >> userAnswer;

        clearScreen(); // clears the screen no matter what input

        if (userAnswer != "y" && userAnswer != "Y")
        {
            clearScreen();
            return 0;

        }
    }


    return 0;
}