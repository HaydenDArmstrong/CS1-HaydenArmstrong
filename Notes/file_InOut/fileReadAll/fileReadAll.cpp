#include <iostream>
#include <fstream>

int main (void)
{

    std::string file_path = "inputfile.txt";
    std::fstream file; // generic filestream object, not input or output

    file.open(file_path, file.ate | file.binary | file.in);


    if(!file.is_open()) //If the file is NOT (!) open, do this...
    {
        std::cout << "Things have gone terribly wrong!" << std::endl;
        return -1; // early return
    }
    size_t size = file.tellg();// tell me the position of the file stream and the size of the file

    file.seekg(0,file.beg);

    std::cout << "size of file: " << size << std::endl;

    char * buffer = new char[size];


   if (file.read(buffer, size)) {

   

    std::cout << "File Contents: " << std::endl << std::endl << buffer << std::endl;
   }
}