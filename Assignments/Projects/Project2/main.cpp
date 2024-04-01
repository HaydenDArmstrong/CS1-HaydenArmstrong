#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.14159
#endif

const double g = 9.81; // Acceleration due to gravity (m/s^2)
const double dt = 0.01; // Time step (s)
const double airDensity = 1.225; // Air density at sea level (kg/m^3)
const double radius = 0.1; // Radius of the projectile (m)
const double area = M_PI * radius * radius; // Cross-sectional area (m^2)

// Structure to hold projectile information
struct Projectile {
    double mass;
    double radius;
    double dragCoefficient;
};

// Function to calculate the acceleration due to air resistance
void airResistance(double vx, double vy, double& ax, double& ay, const Projectile& projectile) {
    double speed = std::sqrt(vx * vx + vy * vy);
    double force = 0.5 * airDensity * projectile.dragCoefficient * area * speed * speed;
    ax = -force / projectile.mass * (vx / speed);
    ay = -force / projectile.mass * (vy / speed);
}

// Function to calculate projectile motion and print results
void calculateProjectileMotion(double angle, double speed, char units, const Projectile& projectile) {
    // Convert angle to radians
    angle = angle * M_PI / 180;

    // Convert speed to meters per second if units are feet per second
    if (units == 'f') {
        speed *= 0.3048; // Conversion factor from feet per second to meters per second
    }

    // Calculate initial velocity components
    double vx = speed * std::cos(angle);
    double vy = speed * std::sin(angle);

    // Simulation loop
    double x = 0, y = 0, time = 0, max_height = 0;
    while (y >= 0) {
        // Update position
        x += vx * dt;
        y += vy * dt;

        // Calculate acceleration due to air resistance
        double ax, ay;
        airResistance(vx, vy, ax, ay, projectile);

        // Update velocity
        vx += ax * dt;
        vy += (-g + ay) * dt; // Include gravity

        // Update max_height
        if (y > max_height) {
            max_height = y;
        }

        // Increment time
        time += dt;
    }

    // Output results
    std::cout << "Flight time: " << std::fixed << std::setprecision(2) << time << " seconds\n";
    std::cout << "Max height: " << std::fixed << std::setprecision(2) << max_height << " meters (" << max_height / 0.3048 << " feet)\n";
    std::cout << "Distance: " << std::fixed << std::setprecision(1) << x << " meters (" << x / 0.3048 << " feet)\n";
}

// Function to generate a 2D array of distances versus angles and velocities
void generateDistanceArray(double max_muzzle_velocity, int num_angles, int num_velocities, const Projectile& projectile, double** distances) {
    // Define the step sizes for angles and velocities
    double angle_step = 90.0 / num_angles;
    double velocity_step = max_muzzle_velocity / num_velocities;

    //angles
    for (int i = 0; i < num_angles; ++i) {
        double angle = i * angle_step;
        // velocities
        for (int j = 0; j < num_velocities; ++j) {
            double velocity = j * velocity_step;
            // Calculate distance for this angle and velocity
            //double distance;
            calculateProjectileMotion(angle, velocity, 'm', projectile); // Assuming units are always meters
            // Store the distance in the array
            // distances[i][j] = distance; // Implement this once distance calculation is done
        }
    }
}

// Function to output a 2D array to a text file
void outputArrayToFile(double** array, int num_angles, int num_velocities, const char* filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < num_angles; ++i) {
            for (int j = 0; j < num_velocities; ++j) {
                file << std::setw(10) << array[i][j] << " "; // Adjust the width as needed
            }
            file << "\n";
        }
        file.close();
        std::cout << "Array has been written to the file: " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

int main() {
    // Projectile information
    Projectile projectile;
    projectile.mass = 30.0; // Mass of the projectile (kg)
    projectile.radius = 0.1; // Radius of the projectile (m)
    projectile.dragCoefficient = 0.47; // Drag coefficient for a sphere

    // Input parameters
    double angle, speed;
    char units;
    std::cout << "Enter angle of launch (degrees): ";
    std::cin >> angle;
    std::cout << "Enter initial speed: ";
    std::cin >> speed;
    std::cout << "Enter units (meters 'm' or feet 'f'): ";
    std::cin >> units;

    // Calculate projectile motion
    calculateProjectileMotion(angle, speed, units, projectile);

    // Example usage for Mode 2
    int num_angles = 10; // Number of angles
    int num_velocities = 10; // Number of velocities
    double max_muzzle_velocity = 100.0; // Maximum muzzle velocity
    double** distances = new double*[num_angles];
    for (int i = 0; i < num_angles; ++i) {
        distances[i] = new double[num_velocities];
    }
    generateDistanceArray(max_muzzle_velocity, num_angles, num_velocities, projectile, distances);

    // Example usage for Mode 3
    // Output the array to a text file
    outputArrayToFile(distances, num_angles, num_velocities, "distance_array.txt");

    // Free memory
    for (int i = 0; i < num_angles; ++i) {
        delete[] distances[i];
    }
    delete[] distances;

    return 0;
}
