#include <iostream>
#include "clock.h"


using namespace std;



void call_clocks(void)
{
    Clock currentTime;
    Clock someotherTimezone(0,0,1);
    Clock currentTimePlus(6331);

    cout << "Hours" << ":" << "minutes" << ":" << "Seconds"<< endl;

    cout << currentTime.hours << ":"
    << currentTime.minutes << ":"
    << currentTime.seconds << endl;
    cout << someotherTimezone.hours << ":"
    << someotherTimezone.minutes << ":"
    << someotherTimezone.seconds << endl;
    cout << currentTimePlus.hours << ":"
    << currentTimePlus.minutes << ":"
    << currentTimePlus.seconds << endl;
}

int main(void)
{
    call_clocks();
    return 0;
}