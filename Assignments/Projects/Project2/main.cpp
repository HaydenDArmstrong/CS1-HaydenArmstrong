#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

#define M_PI 3.14159

// Structure to store projectile information
struct Projectile {
    double mass;
    double radius;
    double dragCoefficient;
    double area; // Adding area member to the structure
};

// Constants
const double g = 9.81; // Acceleration due to gravity (m/s^2)
const double dt = 0.01; // Time step (s)
const double airDensity = 1.225; // Air density at sea level (kg/m^3)

// Function to calculate the acceleration due to air resistance
void airResistance(const Projectile& projectile, double vx, double vy, double& ax, double& ay) {
    double speed = std::sqrt(vx * vx + vy * vy);
    double force = 0.5 * airDensity * projectile.dragCoefficient * projectile.area * speed * speed;
    ax = -force / projectile.mass * (vx / speed);
    ay = -force / projectile.mass * (vy / speed);
}

int main() {
    // Read projectile information from file
    Projectile projectile;
    std::ifstream inputFile("projectile_info.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }
    inputFile >> projectile.mass >> projectile.radius >> projectile.dragCoefficient;
    inputFile.close();

    // Calculate other parameters based on projectile info
    projectile.area = M_PI * projectile.radius * projectile.radius;

    char repeat;
    
    do {

        // Ask to choose use case
        int choice;
        std::cout << "Choose Mode: " << std::endl;
        std::cout << "1: Flight time, Max Height, and Distance Calculator" << std::endl;
        std::cout << "2: Target distance Input, Best Angle/velocity Output" << std::endl;
        std::cout << "3: Distance table given Max Muzzle velocity" << std::endl;
        std::cout << "Which mode would you like to select? ";
        std::cin >> choice;

    
        switch (choice) { // Use case that tracks current xy position relative to time
            case 1: {
                double x = 0, y = 0, time = 0, ax = 0, ay = 0, max_height = 0; // Initial position (m)
                double angle = 0; // Launch angle (degrees)
                double speed = 0; // Initial speed (m/s)

                std::string unit;
                std::cout << "Enter 'feet' or 'meters' for unit of measurement: ";
                std::cin >> unit;

                std::cout << "Angle (Degrees): ";
                std::cin >> angle;
                std::cout << "Speed: ";
                std::cin >> speed;

                if (unit == "feet" || "f") {
                    speed *= 0.3048; // Convert speed to meters per second
                }

                double vx = speed * std::cos(angle * M_PI / 180);
                double vy = speed * std::sin(angle * M_PI / 180);

                double finalDistance;
                double timeTotal;

                // Simulation loop
                while (y >= 0) {
                    // Update position
                    x += vx * dt;
                    y += vy * dt;

                    // Calculate acceleration due to air resistance
                    airResistance(projectile, vx, vy, ax, ay);
                    // ax = 0;  // make air resistance zero
                    // ay = 0;  // make air resistance zero

                    // Update velocity
                    vx += ax * dt;
                    vy += (ay - g) * dt; // Include gravity

                    // Output the current position
                    std::cout << "Position: (" << x << ", " << y << ")" << ", Time: " << time << std::endl;

                    // Or plot an asterisk
                    /*step_num++;
                    if(step_num%2 == 0)
                    {
                        std::cout << std::setw((int)(y*50/37.0)) << '*' 
                        << std::setw(5) << std::fixed << std::setprecision(1) 
                        << y << std::endl;
                    }*/

                    time += dt;
                    if (y > max_height) {
                        max_height = y;
                    }
                    if (x > finalDistance) {
                        finalDistance = x;
                    }
                    if (time > timeTotal) {
                        timeTotal = time;
                    }

                    // Break if the projectile hits the ground
                    if (y < 0) break;
                } // End while

                std::cout << std::endl;
                std::cout << "Max height: " << max_height << std::endl;
                std::cout << "Final Distance travelled: " << finalDistance << std::endl;
                std::cout << "Total time spent travelling: " << timeTotal << std::endl;
                // std::cout << area << sd::endl;
                break;
            }
            case 2: {
                // Case 2: Target distance Input, possible Angle/velocity Output
                double maxMuzzleVelocity;
                double targetDistance;
                std::string unitType;
                std::cout << "Enter a maximum Muzzle velocity in m/s: ";
                std::cin >> maxMuzzleVelocity;
                std::cout << "Enter target distance in meters: ";
                std::cin >> targetDistance;

                // Define the size of the angle-velocity array
                const int numAngles = 91; // 0 to 90 degrees
                const int numCols = 2;    // Angle and Velocity

                // Create a 2D array to store angle-velocity pairs
                double angleVelocityArray[numAngles][numCols];

                // Fill the array with angle-velocity pairs
                for (int i = 0; i < numAngles; ++i) {
                    double angle = i; // Angle from 0 to 90 degrees
                    double velocity = std::sqrt((targetDistance * g) / (std::sin(2 * angle * M_PI / 180))); // Calculate velocity
                    if (velocity <= maxMuzzleVelocity) { // Check if velocity is within limits
                        angleVelocityArray[i][0] = angle;
                        angleVelocityArray[i][1] = velocity;
                    } else {
                        angleVelocityArray[i][0] = angle;
                        angleVelocityArray[i][1] = -1; // Indicates velocity is not possible
                    }
                }

                // Open the CSV file for writing
                std::ofstream outputFile("angle_velocity_table.csv");
                if (!outputFile.is_open()) {
                    std::cerr << "Error: Unable to open file for writing." << std::endl;
                    return 1;
                }

                // Write the angle-velocity pairs to the CSV file
                for (int i = 0; i < numAngles; ++i) {
                    if (angleVelocityArray[i][1] != -1) {
                        outputFile << angleVelocityArray[i][0] << "," << angleVelocityArray[i][1] << "\n";
                    } else {
                        outputFile << angleVelocityArray[i][0] << "," << "not possible" << "\n";
                    }
                }

                // Close the CSV file
                outputFile.close();

                std::cout << "Angle-velocity table has been written to 'angle_velocity_table.csv'." << std::endl;

                // Generate and print three possible solutions
                int count = 0;
                while (count < 3) {
                    int randomIndex = rand() % numAngles; // Generate a random index within the range of angles
                    double angle = angleVelocityArray[randomIndex][0];
                    double velocity = angleVelocityArray[randomIndex][1];
                    if (velocity != -1) {
                        std::cout << "possible Solution " << count + 1 << ": Angle = " << angle << " degrees, Velocity = " << velocity << " m/s\n";
                        count++;
                    }
                }

                break;
            }
            case 3: {
                const int numAngles = 15; // Number of angles (0 to 90)
                const int numVelocities = 30; // Number of muzzle velocities (0 to maxMuzzleVelocity)

                double maxMuzzleVelocity;
                std::cout << "What is maximum muzzle velocity?" << std::endl;
                std::cin >> maxMuzzleVelocity;

                double distances[numAngles][numVelocities]; // Array to store distances

                // Calculate angle and velocity increments
                double angleIncrement = 90.0 / (numAngles - 1);
                double velocityIncrement = maxMuzzleVelocity / (numVelocities - 1);

                // Populate the distances array
                for (int angle = 0; angle < numAngles; ++angle) {
                    double angleDeg = angle * angleIncrement; // Calculate angle in degrees

                    for (int velocity = 0; velocity < numVelocities; ++velocity) {
                        double muzzleVelocity = velocity * velocityIncrement; // Calculate muzzle velocity
                        double angleRad = angleDeg * M_PI / 180.0; // Convert angle to radians

                        // Calculate distance using the current muzzle velocity and angle
                        distances[angle][velocity] =  sin(2 * angleRad) * pow(muzzleVelocity, 2)  / g;
                    }
                }

                // Display the distances and write to file
                std::ofstream outputFile("distances.txt");
                if (!outputFile.is_open()) {
                    std::cerr << "Error: Unable to open file for writing." << std::endl;
                    return 1;
                }

                // Write column headers (velocity)
                outputFile << std::setw(15) << "Angle(deg)";
                for (int velocity = 0; velocity < numVelocities; ++velocity) {
                    outputFile << std::setw(15) << std::fixed << std::setprecision(2) << (velocity * velocityIncrement) << " m/s";
                }
                outputFile << std::endl;

                // Write data
                for (int angle = 0; angle < numAngles; ++angle) {
                    // Write row header (angle)
                    outputFile << std::setw(15) << std::fixed << std::setprecision(1) << (angle * angleIncrement) << " deg";

                    // Write distance values for each angle
                    for (int velocity = 0; velocity < (numVelocities); ++velocity) { 
                        outputFile << std::setw(15) << std::fixed << std::setprecision(3) << distances[angle][velocity];
                    }
                    outputFile << std::endl;
                }

                outputFile.close();

                std::cout << "Distances (in meters) for each angle (0 to 90 degrees) and muzzle velocity (0 to " << maxMuzzleVelocity << " m/s) have been written to 'distances.txt'." << std::endl;

                return 0;
            }

            break;
            default:
                std::cout << "Invalid Choice. Program will now end." << std::endl;
                return 1;
        }
         // Ask if the user wants to continue
        std::cout << "Do you want to perform another case? (Y/N): ";
        std::cin >> repeat;

    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}
