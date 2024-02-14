#include <iostream>

int main()
{
/* comparison operators

x == y equal to 
x!=y not equal to
x > y greater than
x >= y greater than or equal
x < y less than
x <= y less than or equal

*/

int x = 10;
int velocity;
int units;
int answer;

std::cout << (x == 10) << std::endl;
// will output 1 because x = 10. 1= yes 0 = no
std::cout << (x != 10) << std::endl;
// will output 0 because x does equal 10. 
std::cout << (x > 10) << std::endl;
//will output 0 because x is not more than 10
std::cout << (x >= 10) << std::endl;
// will output 1 because x is equivalent or more than 10
std::cout << (x < 10) << std::endl;
// will output 0 because x is not less than 10
std::cout << (x <= 10) << std::endl;
// will output 1 because x is equivalent or less than 10

std::cout << "Would you like to continue the program?" << std::endl;
std::cin >> answer;

if(answer == 'n')
{
    std::cout << "Ending the program..." << std::endl;
    return 0; // if the user says no, the program ends
}

std::cout << "The program is continuing..." << std::endl;

std::cout << "Enter 'f' for feet or 'm' for meters: " << std::endl;
std::cin >> units;

if( units == 'm')
{

    velocity = velocity*0.3048;
}
else{}
std::cout << "Velocity is " << velocity << "m/s" << std::endl;
    return 0;
}