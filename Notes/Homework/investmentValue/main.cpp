#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    double investAmount;
    double interestRate;
    double numOfYears;
    double futureInvestValue;
    double monthlyInterestRate;

    cout << "Enter investment Amount: " << endl;
    cin >> investAmount;
    cout << "Enter annual interest rate in percentage: " << endl;
    cin >> interestRate;
    cout << "Enter number of years: " << endl;
    cin >> numOfYears;

    monthlyInterestRate = interestRate / 100 / 12;

// futureInvestmentValue = investmentAmount x (1 + monthlyInterestRate)^(numberOfYears x 12)
    futureInvestValue = investAmount * pow((1 + monthlyInterestRate), (numOfYears * 12 ));



    cout << "accumulated value is: " << futureInvestValue << endl;

    return 0;
}