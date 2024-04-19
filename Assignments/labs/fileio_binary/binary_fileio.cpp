/*
Hayden Armstrong
4/19/2024
File IO Lab: Reading binary data and random file access.
*/

#include <iostream>
#include <fstream>

struct Student
{
    char name[260];
    int id;
    double grades[10];
    double average;
};

void printRecord(Student record);

int main(int argc, char*argv[])
{
    // FIXME3: make a varible named "record" to store a student record using 
    //         the Student type defined above
    Student record;
    //TYPE record
    std::ifstream fin;

    srand(time(NULL));
    int rand_rec_num = rand()%11;
    std::cout << "Random record num = " << rand_rec_num << std::endl;

    fin.open("student_records.bin", std::ios::binary | std::ios::out);
    
    // FIXME4 check if file is open, if not return -1
    if (!fin.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return -1;
}
    
    fin.seekg(rand_rec_num*sizeof(Student), fin.beg);  // Seek random record
    fin.read(reinterpret_cast<char*>(&record), sizeof(Student));
    printRecord(record);

    fin.seekg(0, fin.end); // Go to end of file
    unsigned int filesize = fin.tellg();
    std::cout << "File size in bytes is " << filesize << std::endl;
    std::cout << "File contains " << filesize/sizeof(Student) << " records." << std::endl;

    // FIXME6 seek and read in the second to last record
    fin.seekg(-2 * static_cast<int>(sizeof(Student)), std::ios_base::end);
    fin.read(reinterpret_cast<char*>(&record), sizeof(Student));
    // FIXME7 print that record
    printRecord(record);
    // FIXME8: seek back to beginning of file
    fin.seekg(0, fin.beg);
    // FIXME9: read and print records until end of file, HINT: use loop of number of records or fin.tellg()==filesize to end
        while (fin.read(reinterpret_cast<char*>(&record), sizeof(Student))) {
        printRecord(record);
    }
    fin.close();

    return 0;
}

void printRecord(Student record)
{
    // FIXME 5 output student name, id, grades, and average grade with proper descriptions
    //EX:
    /*
    Corin Chepko, 700123456, Grades: 1 2 3 4 5 6 7 8 9 10, Avg Grade: 5
    */
   std::cout << "Name: " << record.name << ", ID: " << record.id << ", Grades: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << record.grades[i] << " ";
    }
    std::cout << ", Avg Grade: " << record.average << std::endl;
    std::cout << record.name << std::endl;
}