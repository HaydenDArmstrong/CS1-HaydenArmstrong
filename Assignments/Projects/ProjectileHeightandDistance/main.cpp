#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
{
    // constant variables - gravity and unit conversions
    const double GRAVITY = 9.81;
    const double MeterToFeet = 3.28;
    const double FeetToMeter = 1 / MeterToFeet;

    // terms to use in calculations
    double alpha; 
    double muzzleVelocity;
    double targetDistance;

    // unit type response from user
    string unitType;





    cout << "Unit type: Feet or Meters? " << endl;
    cin >> unitType; // feet or meters? 
    if (unitType == "feet" || unitType == "foot") 
    {
        cout << "What is the speed at which the projectile leaves the Cannon in Feet Per second? " << endl;
        cin >> muzzleVelocity;
        cout << "What is the horizontal target distance from the cannon in Feet? " << endl;
        cin >> targetDistance;

        //unit conversion if given feet
        muzzleVelocity *= FeetToMeter;
        targetDistance *= FeetToMeter;
    } 
    else if (unitType == "meters" || "meter")
    {
        cout << "What is the speed at which the projectile leaves the Cannon in Meters Per second? " << endl;
        cin >> muzzleVelocity;
        cout << "What is the horizontal target distance from the cannon in Meters? " << endl;
        cin >> targetDistance; 
    }

    cout << "What angle is the Cannon pointing at in Degrees? " << endl;
    cin >> alpha;

     // Convert angle to radians
    double angleRad = alpha * M_PI / 180.0; 



    double flightTime = (2 * muzzleVelocity * sin(angleRad)) / GRAVITY;
    double maxHeight = pow(muzzleVelocity * sin(angleRad), 2) / (2 * GRAVITY);
    double xDistance = muzzleVelocity * cos(angleRad) * flightTime;

    cout << "Flight Time: " << flightTime << " seconds " << fixed << setprecision(2) << endl;
    cout << "Maximum height: " << maxHeight << " meters" << fixed << setprecision(2) << endl; //maximum height is wrong
    cout << "Travelled Distance " << xDistance << fixed << " meters" << setprecision(1) << endl; // travelled distance is wrong

    cout << "\n\n";

    if (xDistance > targetDistance)
    {
        cout << "Travelled Distance is more than target";
    } else if (xDistance == targetDistance)
    {
        cout << "Target Distance Met!";
    }
    else
    {
        cout << "Travelled Distance is less than target";
    }


    /* 
    ending statement- how to make it so if you respond with somehting other than foot/feet/meter/meters, program ends??
    cout << "Unable to determine unit type from response." << endl;
    cin.ignore(1000, '\n');
    cout << "Please Press Enter and Rerun Program. ";
    cin.get();
    cout << "Goodbye." << endl;
    */


    return 0;
}