#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream inputFile("Exercise13_3.txt"); // Open the file for input
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int total = 0;
    int count = 0;
    std::string line;

    // Read lines from the file
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int number;

        // Read numbers from each line
        while (iss >> number) {
            total += number;
            count++;
        }
    }

    // Close the file
    inputFile.close();

    // Calculate the average
    double average = count > 0 ? static_cast<double>(total) / count : 0;

    // Display total and average
    std::cout << "Total is " << total << std::endl;
    std::cout << "Average is " << average << std::endl;

    return 0;
}
