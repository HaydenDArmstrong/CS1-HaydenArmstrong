#include <iostream>

using namespace std;

int main(void)
{
    string phrase = "This is a sentence!";
    char phrase2[260];

    cout << phrase << endl;

    for (char ch: phrase)
    {
        cout << ch << ' ';
    }

    cout << phrase2 << endl;

    for (char ch: phrase)
    {
        cout << ch << ' ';
    }

    return 0; 
}
