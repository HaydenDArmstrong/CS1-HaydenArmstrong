/*
Ongoing Notes for C++ fundamentals Homework
Hayden Armstrong
*/

#include <iostream>
#include <iomanip>

int main()
{
    //-----increment and decrement operators----

    int blue = 1;
    int red = blue;
    std::cout << "blue is " << blue;
    std::cout << " and red is " << red << std::endl;
    //unchanged. red=blue and the values will never change

    int a = 1;
    int b = a++;
    std::cout << "a is " << a;
    std::cout << " and b is " << b << " In a result of a a++ operation. " << std::endl;
    // in this case a is initally equal to 1. b first declares i's value, then adds 1 to a.
    // a is now 2 while b remains one.

    int c = 1;
    int d = ++c;
    std::cout << "c is " << c;
    std::cout << " and d is " << d << " In a result of a ++c operation. " << std::endl;
    // in this case c is initally equal to 1. 
    // 1 is first added to c, making c equal to 2, then d declares its value, which is now also 2.
    // c is made 2 and d outputs itself as 2

    int e = 1;
    int f = e--;
    std::cout << "e is " << e;
    std::cout << " and f is " << f << " In a result of a e-- operation. " << std::endl;

    int g = 1;
    int h = --g;
    std::cout << "g is " << g;
    std::cout << " and h is " << h << " In a result of a --g operation. " << std::endl;
    

    std::cout << "\n";

    //----Assignment Operators----

    double count = 3;
    count += 2;
    std::cout << "double count is 3 + 2, which results in: " << count << std::endl;
    // operation which results in two being added to the double 'count' through +=

    double count2 = 3;
    count2 /= 2;
    std::cout << "double count2 is 3 / 2, which results in: " << count2 << std::endl;
    // operation which results in double being dividved by 2  through /=

    int count3 = 3;
    count3 /= 2;
    std::cout << "int count2 is 3 / 2, which results in: " << count3 << std::endl;

    std::cout << "\n";

    //----Data Conversion and casting----

    double castednarrow = static_cast<double>(5/2); 
    // double cast result of two integers. 
    // because the integers are calculated beforehand, the result is 2.0, with the .5 truncated

    double castedwide = static_cast<double>(5)/2; 
    // double cast result of two integers undergoing a double operation.
    // the integers are calculated as doubles, the result is 2.5

    int intcomparison = 2; 
    // integer for terminal comparison. 
    // The integer when the precision is set to two decimal points will still remain 2, not 2.0

    std::cout << "result of casted double, with the operation happening as a integer: " << 
    std::fixed << std::setprecision(2) << castednarrow << std::endl;
    std::cout << "result of casted double, with the operation happening as a double: " <<
    std::fixed << std::setprecision(2) << castedwide << std::endl;
    std::cout << "A regular integer operation for comparison: " <<
    std::fixed << std::setprecision(2) << intcomparison << std::endl;
    // notice that even when integer precison is set to 2 decimals, the output is still 2, not 2.0. 
    // integers NEVER include decimals

    std::cout << "\n";

    return 0;
}