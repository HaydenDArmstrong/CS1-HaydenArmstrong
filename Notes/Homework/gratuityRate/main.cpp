#include <iostream>

using namespace std;

int main()
{
    double subtotal;
    double total;
    double gratuityRate;
    double gratuity;

    cout << "Enter the subtotal and a gratuity rate" << endl;
    cin >> subtotal >> gratuityRate;

    gratuity =  (gratuityRate / 100) * subtotal;

    total =  gratuity + subtotal;
    
    cout << " The Gratuity is $" << gratuity << " and total is $" << total << endl;

    return 0;
}

