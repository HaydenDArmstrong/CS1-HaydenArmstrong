#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

#define M_PI 3.14159

// Constants
const double g = 9.81; // Acceleration due to gravity (m/s^2)
const double dt = 0.01; // Time step (s)
const double airDensity = 1.225; // Air density at sea level (kg/m^3)
const double dragCoefficient = 0.47; // Drag coefficient for a sphere
const double radius = 0.3; // Radius of the projectile (m)
const double area = M_PI * radius * radius; // Cross-sectional area (m^2)
const double mass = 3.0; // Mass of the projectile (kg)

// Function to calculate the acceleration due to air resistance
void airResistance(double vx, double vy, double &ax, double &ay) 
{
    double speed = std::sqrt(vx * vx + vy * vy);
    double force = 0.5 * airDensity * dragCoefficient * area * speed * speed;
    ax = -force / mass * (vx / speed);
    ay = -force / mass * (vy / speed);
}


// Structure to store projectile information
struct Projectile {
    double mass;
    double radius;
    double dragCoefficient;
};




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
    double area = M_PI * projectile.radius * projectile.radius;

    //ask to choose use case
    int choice;
    std::cout << "Choose Mode: ";
    std::cin >> choice;

    switch (choice) { //use case that tracks current xy position relative to time
        case 1: { 
    double x = 0, y = 0, time=0, ax=0, ay=0, max_height = 0; // Initial position (m)
    double angle = 45; // Launch angle (degrees)
    double speed = 50; // Initial speed (m/s)
    double vx = speed * std::cos(angle * M_PI / 180);
    double vy = speed * std::sin(angle * M_PI / 180);

    int step_num=0;
    // Simulation loop
    while (y >= 0) 
    {
        // Update position
        x += vx * dt;
        y += vy * dt;

        // Calculate acceleration due to air resistance
        airResistance(vx, vy, ax, ay);
        //ax = 0;  // make air resistance zero
        //ay = 0;  // make air resistance zero

        // Update velocity
        vx += ax * dt;
        vy += (ay - g) * dt; // Include gravity

        // Output the current position
        std::cout << "Position: (" << x << ", " << y << ")" << ", Time: " << time << std::endl;
        
        //Or plot an asterisk
        /*step_num++;
        if(step_num%2 == 0)
        {
            std::cout << std::setw((int)(y*50/37.0)) << '*' 
            << std::setw(5) << std::fixed << std::setprecision(1) 
            << y << std::endl;
        }*/

        time += dt;
        if(y > max_height)
        {
            max_height = y;
        }

        // Break if the projectile hits the ground
        if (y < 0) break;

    }  // End while
    std::cout << "Max height: " << max_height << std::endl;
    std::cout << area << std::endl;
            break;
        }
        case 2: {
            //Case where given Maximum muzzle velocity, and target distance, find optimal angle and velocity using a distance vs angle array. 
            //output angle and velocity to console
            double maxMuzzleVelocity;
            std::string unitType;
            std::cout << "Unit type: Feet or Meters? ";
            std::cin >> unitType;
            if (unitType == "feet" || unitType == "foot" || unitType == "Feet" || unitType == "Foot") {
                std::cout << "What is Maximum muzzle Velocity? ";
                std::cin >> maxMuzzleVelocity;
            } else if (unitType == "meters" || unitType == "meter" || unitType == "Meters" || unitType == "Meter") {
                std::cout << "What is Maximum muzzle Velocity? ";
                std::cin >> maxMuzzleVelocity;
            } else {
                std::cout << "Invalid Input" << std::endl;
            }
            break;
        }
        case 101: {
            // Your existing case 101 code here...
            break;
        }
        default:
            std::cout << "Invalid Choice. Program will now end." << std::endl;
            return 1;
    }

    return 0;
}