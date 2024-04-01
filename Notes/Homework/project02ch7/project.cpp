#include <iostream>
using namespace std;

int main()
{
    const int MAX_SIZE = 100;
    int occo[101] = {0};
    int num;

    cout << "Enter the integers between 1 and 100:";

     // Read integers until 0 is encountered
    while (cin >> num && num != 0) {
        if (num >= 1 && num <= 100) {
            occo[num]++;
        }
    }

    // Print occurrences
    for (int i = 1; i <= 100; ++i) {
        if (occo[i] != 0) {
            cout << i << " occurs " << occo[i] << (occo[i] > 1 ? " times" : " time") << endl;
        }
    }

    return 0;

}