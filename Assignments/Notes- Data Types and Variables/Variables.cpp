#include <iostream>

using namespace std;

int main(void)
{
    char middleinitial = 'D';
    int exampleInteger;
    double exampleDouble;
    float exampleFloat;
    const double pi = 3.14159; // constant is unmodifiable, if i do pi = 4; , will receive an error
    string name = "Hayden";
    /* 
    basic escape characters 
    \n - new line
    \ - back slash
    \t - tab
    \r - carriage return
    \' - single quote
    \" - double quote
    */
    string phrase = "\n\n\n new line \n\n\n";
    string phrasereturn = "\r carriage return /r";

    exampleDouble = 50; // assigned variable to 50

    cout << "Hello " << name << " " << middleinitial << endl;
    cout << "Integer Example: " << exampleInteger << endl;
    cout << "Double Example " << exampleDouble << endl;

    cout << phrase << endl;
    cout << phrasereturn << endl;

    return 0;
}
