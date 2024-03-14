#include <iostream>

using namespace std;

int main(void)
{
    int num_students, best=0;

    cout << "Enter Number of scores " << endl;

    cin >> num_students;

    int *scores = new int[num_students]; //allocate an array of size num_students
        //address of beginning of array is scores

        for(int i=0; i<num_students; i++)
        {
            cin >> scores[i];
            if (scores[i] > best)
            {
                cout << "Nice";
            }
        }
        cout << "Enter " << num_students << " Scores: " << endl;

        for (int i=0; i<num_students; i++)
        {
            cout << "Score of student " << i << " is " << scores[i];
            cout << endl;
        }
        return 0;
}