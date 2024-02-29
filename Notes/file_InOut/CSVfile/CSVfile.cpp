#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char * argv[])
{
    /*if(argc > 1 && argv[1] = "test")
    {
        std::cout << "test " << std::endl;
        return 0;
    }*/

    std::string header_x, header_y;
    std::fstream file; 
    double time, height;
    std::string time_s, height_s;

    file.open("csvfile.txt");

    if (!file.is_open())
    {
        std::cout << "Could Not open file" << std::endl;
        return -1;
    }

    getline(file, header_x, ','); // Read until sees delimiter, specified to be ',' in this case
    getline(file, header_y); // Read until sees delimiter, end of line

    std::cout << header_x << std::endl;
    std::cout << header_y << std::endl;
   
    for (int i=0; i < 8; i++)
    {
        getline(file, time_s, ',');
        getline(file, height_s);
        time = stof(time_s); 
        height = stof(height_s); 
        std::cout << time;

        for(int j=0; j<height-1; j++)
        {
            std::cout << ' ';
        }
        std::cout << '*' << std::endl;
    }

    return 0;

}