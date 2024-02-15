#include <iostream>

int main(int argc, char* argv[])
{
    // argc is the number of arguments, always at least one which is the program name
    // argv is a pointer to a character arrays that contain the string
    std::cout << "Number of arguments to main =  " << argc << std::endl;
    std::cout << "Our program name and path: " << argv[0] << std::endl;
    std::cout << "The second argument: " << argv[1] << std::endl; // the first argument is the inital executable

    if ( argc > 1 && std::string(argv[1]) == "test" )
    {
        std::cout << "Testing \n";
    }
    return 0;
}