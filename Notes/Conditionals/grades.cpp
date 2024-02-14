#include <iostream>

using namespace std;

int main(void)
{
    float grade;
    string letter;

    cout << "What is your number Grade?" << endl;
    cin >> grade;

    if (grade >= 90)
    {
        letter = 'A';
    }
    else if ( grade >= 80)
    {
        letter = 'B';
    }
    else if ( grade >= 70)
    {
        letter = 'C';
    }
    else if ( grade >= 60)
    {
        letter = 'D';
    }
    else 
    {
        letter = 'F';
    }

    cout << "The number grade of " << grade << " is a " << letter << " Letter Grade." << endl;

    return 0;
}