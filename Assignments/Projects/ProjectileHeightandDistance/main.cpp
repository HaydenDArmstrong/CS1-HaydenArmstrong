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

    //arithmetic fix: console outputs less than or more than 0.0 meters from target. I think its something to do with double values
    //so i decided to make a range which allows for target distance to still be met
    // if target distance is within one meter less or more than actual distance, still outputs distance met
    const double acceptedRange = 1.0;

    // terms to use in calculations
    double alpha; 
    double muzzleVelocity;
    double targetDistance;

    // unit type response from user
    string unitType;





    cout << "Unit type: Feet or Meters? " << endl;
    cin >> unitType; // feet or meters? 
    if (unitType == "feet" || unitType == "foot" || unitType == "Feet" || unitType == "Foot") 
    {
        cout << "What is the speed at which the projectile leaves the Cannon in Feet Per second? " << endl;
        cin >> muzzleVelocity;
        cout << "What is the horizontal target distance from the cannon in Feet? " << endl;
        cin >> targetDistance;

        //unit conversion if given feet
        muzzleVelocity *= FeetToMeter;
        targetDistance *= FeetToMeter;
    } 
    else if (unitType == "meters" || unitType == "meter" || unitType == "Meters" || unitType == "Meter")
    {
        cout << "What is the speed at which the projectile leaves the Cannon in Meters Per second? " << endl;
        cin >> muzzleVelocity;
        cout << "What is the horizontal target distance from the cannon in Meters? " << endl;
        cin >> targetDistance; 
    }
    else // if given something else than feet/meter
    {
        cout << "Invalid Input. Program will now end." << endl;
        return 1;
    }

    cout << "What angle is the Cannon pointing at in Degrees? " << endl;
    cin >> alpha;

     // Convert angle from degree to radians for calculation
    double angleRad = alpha * M_PI / 180.0; 



    double flightTime = (2 * muzzleVelocity * sin(angleRad)) / GRAVITY;
    double maxHeight = pow(muzzleVelocity * sin(angleRad), 2) / (2 * GRAVITY);
    double actualDistance = muzzleVelocity * cos(angleRad) * flightTime;

    cout << "Flight Time: " << fixed << setprecision(2) <<  flightTime << " seconds "  << endl;
    cout << "Maximum height: " << fixed << setprecision(2) << maxHeight << " meters"  << endl; 
    cout << "Travelled Distance "  << fixed << setprecision(1) << actualDistance << " meters" << endl;

    cout << "\n\n";

    if (actualDistance > targetDistance)
    {
        cout << "Travelled Distance is more than target by " << actualDistance - targetDistance << " meters. Out of Range" << endl;;
    } else if (actualDistance >= targetDistance - acceptedRange && actualDistance <= targetDistance + acceptedRange) 
    // if target = actual within +- 1 meter, return with "distance met"
    {
        cout << "Target Distance Met!"; 
    }
    else
    {
        cout << "Travelled Distance is less than target by " << targetDistance - actualDistance << " meters. Within range" << endl;
    }
    
    
    return 0;
}