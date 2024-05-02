#include <iostream>
#include <cstring>

using namespace std;

struct STUDENT //everything in a structgure is public, available for anyone to use
{
    char name[25];
    int id;
    float grade;

    void double_grade()
    {
        grade = grade*2;
    }
};
class STUDENTE
{
private:
    int valuable;
public:     //makes a class act similarly like a structure, with public access
    char name[25];
    int ID;
    float grade;
    STUDENTE(char name_e[25], int id, float g)
    {
        strncpy(name, name_e, 25);
        ID = id;
        grade = g;
    }


    void double_grade()
    {
        grade = grade*2;
    }
};
int main(void)
{
    STUDENT stud; // used default empty construct to create instance 
    stud.name[0] = 'C';
    stud.name[1] = '\0';
    STUDENT stud = {"CIRUB", 700, 50};

    cout << stud.name << " " << stud.grade << endl;

    stud.double_grade();

}