#include <iostream>

using namespace std;

int main(){

    int minuteInput;
    int numberOfYears;
    int totalNumberOfDays;
    int remainingDays;

    cout << "Enter the Number of Minutes: " << endl;
    cin >> minuteInput;

    totalNumberOfDays = minuteInput / (24*60)  ;
    numberOfYears = totalNumberOfDays / 365;
    remainingDays = totalNumberOfDays % 365;

    cout << minuteInput << " Minutes is approximately " << numberOfYears << " Years and " << remainingDays << " Days";

    return 0;
}