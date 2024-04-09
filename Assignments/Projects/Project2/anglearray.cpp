#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

#define M_PI 3.14159

// Constants
const double GRAVITY = 9.81;

int main() {
    const int numAngles = 10; // Number of angles (0 to 90)
    const int numVelocities = 10; // Number of muzzle velocities (0 to maxMuzzleVelocity)
    const double maxMuzzleVelocity = 450.0; //set 450 for example. FUTURE VARIABLE FROM USER INPUT
    double distances[numAngles][numVelocities]; // Array to store distances

    // Populate the distances array
    for (int angle = 0; angle <= 90; angle += 10) {
        double angleRad = angle * M_PI / 180.0; // Convert angle to radians
        for (int velocity = 0; velocity <= numVelocities; ++velocity) {
            double muzzleVelocity = velocity * maxMuzzleVelocity / numVelocities;
            distances[angle / 10][velocity] = pow(muzzleVelocity, 2) * sin(2 * angleRad) / GRAVITY;
        }
    }

    // Display the distances and write to file
    std::ofstream outputFile("distances.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return 1;
    }

    // Write column headers (velocity)
    outputFile << std::setw(10) << "Angle(deg)";
    for (int velocity = 0; velocity <= numVelocities; ++velocity) {
        outputFile << std::setw(10) << (velocity * maxMuzzleVelocity / numVelocities) << " m/s";
    }
    outputFile << std::endl;

    // Write data
    for (int angle = 0; angle <= 90; angle += 10) {
        // Write row header (angle)
        outputFile << std::setw(10) << angle << " deg";

        // Write distance values for each angle
        for (int velocity = 0; velocity <= numVelocities; ++velocity) {
            outputFile << std::setw(10) << std::fixed << std::setprecision(2) << distances[angle / 10][velocity];
        }
        outputFile << std::endl;
    }

    outputFile.close();

    std::cout << "Distances (in meters) for each angle (0 to 90 degrees) and muzzle velocity (0 to 450 m/s) have been written to 'distances.txt'." << std::endl;

    return 0;
}
