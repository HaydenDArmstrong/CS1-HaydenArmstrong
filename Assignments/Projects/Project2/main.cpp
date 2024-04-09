#include <iostream>
#include <iomanip>
#include <cmath>

#define M_PI 3.14159

// Constants
const double GRAVITY = 9.81;
const double MeterToFeet = 3.28;
const double FeetToMeter = 1 / MeterToFeet;
const double g = 9.81;
const double dt = 0.01;
const double airDensity = 1.225;
const double dragCoefficient = 0.47;
const double radius = 0.3;
const double area = M_PI * radius * radius;
const double mass = 3.0;
const double acceptedRange = 1.0;

// Function to calculate the acceleration due to air resistance
void airResistance(double vx, double vy, double& ax, double& ay) {
    double speedSquared = vx * vx + vy * vy;
    double force = 0.5 * airDensity * dragCoefficient * area * speedSquared;
    double speed = sqrt(speedSquared);
    ax = -force / mass * (vx / speed);
    ay = -force / mass * (vy / speed) - g;
}

int main() {
    int choice;
    std::cout << "Choose Mode: ";
    std::cin >> choice;
    std::cout << std::setw(80) << std::setfill('=') << ' ' << std::endl;

    switch (choice) {
        case 1: { //OG case- output flight time, max height, travelled distance. probably delete later
            double alpha, muzzleVelocity, targetDistance;
            std::string unitType;

            std::cout << "Unit type: Feet or Meters? ";
            std::cin >> unitType;

            std::cout << std::setw(80) << std::setfill('=') << ' ' << std::endl;

            if (unitType == "feet" || unitType == "foot" || unitType == "Feet" || unitType == "Foot") {
                std::cout << "Speed at which the projectile leaves the Cannon in Feet Per second: ";
                std::cin >> muzzleVelocity;
                std::cout << "Horizontal target distance from the cannon in Feet: ";
                std::cin >> targetDistance;
                muzzleVelocity *= FeetToMeter;
            } else if (unitType == "meters" || unitType == "meter" || unitType == "Meters" || unitType == "Meter") {
                std::cout << "Speed at which the projectile leaves the Cannon in Meters Per second: ";
                std::cin >> muzzleVelocity;
                std::cout << "Horizontal target distance from the cannon in Meters: ";
                std::cin >> targetDistance;
            } else {
                std::cout << "Invalid Input. Program will now end." << std::endl;
                return 1;
            }

            std::cout << "Angle of the Cannon in Degrees: ";
            std::cin >> alpha;
            std::cout << std::setw(80) << std::setfill('=') << ' ' << std::endl;

            double angleRad = alpha * M_PI / 180.0;

            double flightTime = (2 * muzzleVelocity * sin(angleRad)) / GRAVITY;
            double maxHeight = pow(muzzleVelocity * sin(angleRad), 2) / (2 * GRAVITY);
            double actualDistance = pow(muzzleVelocity, 2) * sin(2 * angleRad) / GRAVITY;

            double actualDistanceUnit = (unitType == "feet" || unitType == "foot" || unitType == "Feet" || unitType == "Foot") ? actualDistance * MeterToFeet : actualDistance;

            std::cout << std::setw(80) << std::setfill('=') << ' ' << std::endl;
            std::cout << "Flight Time: " << std::fixed << std::setprecision(2) << flightTime << " seconds" << std::endl;
            std::cout << "Maximum height: " << std::fixed << std::setprecision(2) << maxHeight << " " << ((unitType == "feet" || unitType == "foot" || unitType == "Feet" || unitType == "Foot") ? "feet" : "meters") << std::endl;
            std::cout << "Travelled Distance: " << std::fixed << std::setprecision(1) << actualDistanceUnit << " " << ((unitType == "feet" || unitType == "foot" || unitType == "Feet" || unitType == "Foot") ? "feet" : "meters") << std::endl;

            std::cout << std::setw(80) << std::setfill('=') << ' ' << std::endl;

            double distanceDiff = actualDistanceUnit - targetDistance;
            if (std::abs(distanceDiff) <= acceptedRange) {
                std::cout << "Target Distance Met!" << std::endl;
            } else {
                std::cout << "Travelled Distance is " << (distanceDiff > 0 ? "more" : "less") << " than target by " << std::abs(distanceDiff) << " " << ((unitType == "feet" || unitType == "foot" || unitType == "Feet" || unitType == "Foot") ? "feet" : "meters") << "." << std::endl;
            }

            std::cout << std::setw(80) << std::setfill('=') << ' ' << std::endl;
            break;
        }
        case 2: { //Case where given Maximum muzzle velocity, and target distance, find optimal angle and velocity (future second case)
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
        case 101: { //case  tracks position and time (future first case)
            double x = 0, y = 0, max_height = 0, timeTrack = 0, vx, vy;
            double angle = 45, speed = 100;
            vx = speed * cos(angle * M_PI / 180);
            vy = speed * sin(angle * M_PI / 180);
            while (y >= 0) {
                x += vx * dt;
                y += vy * dt;
                double ax, ay;
                airResistance(vx, vy, ax, ay);
                vx += ax * dt;
                vy += ay * dt;
                std::cout << "Position: (" << x << ", " << y << "), Time: " << timeTrack << std::endl;
                timeTrack += dt;
                if (y > max_height) {
                    max_height = y;
                }
            }
            std::cout << "Max height: " << max_height << std::endl;
            break;
        }
        default:
            std::cout << "Invalid Choice. Program will now end." << std::endl;
            return 1;
    }
    return 0;
}