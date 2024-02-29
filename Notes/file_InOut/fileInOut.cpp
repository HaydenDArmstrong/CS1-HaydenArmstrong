#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    string filename;
    string name = "";
    float grade = 0;
    float temp;

    int count = 5;

    cout << "Enter a file name to open: " << endl;
    cin >> filename;

    fstream fin; 
    fstream fout("output.txt"); // by default opens a file in text mode and clears contents of file

    fin.open(filename);

    while(!fin.eof()) //while NOT (!) at the end of the file, continue loop
    {
        fin >> name;
        for(int i = 0; i<count; i++)
        {
            fin >> temp;
            grade += temp;
        }
        grade /= count; //average compute

        cout << name << " has an average score of " 
            << grade << endl;
        fout << name << " has an average score of " 
            << grade << endl;
    }

    fin.seekg(0, fin.beg);

   /* getline(fin, stuff);
    cout << "things " << stuff << endl;
    getline(fin, stuff);
    cout < stuff << endl;
    */

    fin.close();
    fout.close();


    return 0;
}