#include <iostream>


#ifndef ClockClass
#define ClockClass

using namespace std;
class Clock
{
private:
    int num_clocks = 0;
public:
    int seconds, minutes, hours;
    
    Clock()
    {
    seconds = 0;
    minutes = 0;
    hours = 0;
    cout << "I am constructed" << endl;
    num_clocks++;
    }
    Clock(int s)
    {
        minutes = s/60;
        seconds = s%60;

        hours = minutes/60;
        minutes = minutes%60;

    }
    Clock(int s, int m, int h)
    {
        if(s >= 60)
        {
            seconds = 0;
        }
        else
        {
                seconds = s;
        }
        if(m >= 60)
        {
            minutes = 0;
        }
        else
        {
                minutes = m;;
        }
        hours = h;
        cout << "I am constructed with a parameterized constructor" << endl;;
        num_clocks++;
    }
    ~Clock()
    {
        cout << "Done with clock"<< endl;
        cout << "Number of clocks:" << num_clocks << endl;
    }
};

#endif