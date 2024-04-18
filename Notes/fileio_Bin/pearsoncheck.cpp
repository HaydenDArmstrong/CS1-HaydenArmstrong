#include <iostream>
#include <fstream>

int main() {
    // Open the file in append mode
    std::ofstream outputFile("Exercise13_1.txt", std::ios::app);

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1;
    }

    // Write 100 integers from 0 to 99 into the file
    for (int i = 0; i < 100; ++i) {
        outputFile << i << " ";
    }

    // Close the file
    outputFile.close();

    std::cout << "Data has been written to Exercise13_1.txt" << std::endl;

    return 0;
}
