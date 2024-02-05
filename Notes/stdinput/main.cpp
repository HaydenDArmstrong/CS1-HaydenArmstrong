#include <iostream>


int main(void)
{
    int int_num = 0;
    int int_num2;
    double double_num;
    char c_string[260];
    std::string lname;

   
    std::cout << "Enter three Numbers (last can be Double) \n"; // Ask for Numbers

    std::cin >> int_num >> int_num2 >> double_num;

    std::cout << "int_num = " << int_num << std::endl;
    std::cout << "int_num2 = " << int_num2 << std::endl;
    std::cout << "double_num = " << double_num << std::endl; // Output Numbers, two integer numbers and a double number

    std::cout << "Enter Your Name "; // Ask for name

    std::cin >> c_string >> lname; // c string = first name, lname= last name

    std:: cout << "Hello " << c_string <<  ' ' << lname << '!' << std::endl; // Output Name

    /*
    std::string phrase;
    std::getline(std::cin, phrase);
    std::cout << phrase; 
    */

    std::cout << "Press ENTER to Continue...." << std::endl;
    std::cin.ignore(1000, '\n');  // This function ignores and discards number of characters
    // Now we can proceed with a getline() and itll collect the whole 
    // a cin.get() will also discard the hanging '\n'
    std::string phrase;
    std::getline(std::cin, phrase);
    std::cout << phrase;

    int time;
    std::cout << "Enter a time in minutes: ";
    std::cin >> time;
    int hours = time/60;
    int minutes = time%60; // remainder of time/60 

    std::cout << time << " Minutes = " << hours << " Hours and " << minutes << " Minutes";
    
    return 0;
}