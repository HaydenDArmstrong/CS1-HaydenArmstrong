/*
    StdIO Lab
    ASCII Art - using literals and variables
    
    Updated By: Hayden Armstrong
    Date: 2/1/2024
    
    This program produces an ASCII art on the console.

    Algorithm steps: 
    1. Use variables to store data/values
    2. Write a series of cout statements to print the data/values
*/

#include <iostream> //library for input and output
#include <string> //library for string data
 
using namespace std; //resolve cout, cin, and endl names
 
//main entry point of the program
int main()
{
    //FIXME3: declare a variable to store name
    string name;
    //FIXME4: prompt user to enter their name and store the value into name variable using getline function
    cout << "Please enter your name: ";
    cin >> name;
        //FIXME5: greet the name using the variable as the following output
        //must output: Nice meeting you, <name>!
        cout << "Nice meeting you, " << name << "!" << endl;
        cout << "Hope you like my ASCII art...\n\n";

        string line1 = "    |\\_/|        **********************    (\\\\___//)  \n";
        string line2 = "    (--_--)      **********************    {-o---o-}    \n";
        string line3 = "   _|    |__     **********************    {  -0-  }    \n";
        string line4 = "__/ |  . |  \\__  **********************    {       }    \n";
        string line5 = "    |  _ |       **********************    {       }    \n";
        string line6 = "    | || |       **********************    {   _   }~~  \n";
        string line7 = "    |__|__|      **********************     |_| |_|     \n";

        cout << line1;
        cout << line2;
        cout << line3;
        cout << line4;
        cout << line5;
        cout << line6;
        cout << line7;


        //FIXME6: use variable to print the second line line of the graphic
        //FIXME7: print the third line of the graphics
        //FIXME8: use variable to print the fourth line
        //FIXME9: use variable to print the fifth line
        //Note: You can add more lines or print more ASCII arts of your choice if you'd like...

        cout << "\nGood bye... hit enter to exit the program: " << '\n';
         //FIXME10: make the console wait for user input
    }