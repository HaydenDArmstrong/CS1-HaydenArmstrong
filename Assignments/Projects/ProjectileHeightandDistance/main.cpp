/*
    Projectile Height and Distance Calculator
    
    Updated By: Hayden Armstrong
    First Submission Date: 2/21/2024
    REDONE: 2/29/2024
    
    *Changed so outputs to both feet and meters
*/

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



    cout << "Unit type: Feet or Meters? ";

    cin >> unitType; // feet or meters? 


    cout << setw(80) << setfill('=') << ' ' << endl;

    if (unitType == "feet" || unitType == "foot" || unitType == "Feet" || unitType == "Foot") 
    {
        cout << "What is the speed at which the projectile leaves the Cannon in Feet Per second? " << endl;
        cin >> muzzleVelocity;
        cout << "What is the horizontal target distance from the cannon in Feet? " << endl;
        cin >> targetDistance;

        //unit conversion if given feet
        muzzleVelocity *= FeetToMeter;
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

    cout << setw(80) << setfill('=') << ' ' << endl;

     // Convert angle from degree to radians for calculation
    double angleRad = alpha * M_PI / 180.0; 



    double flightTime = (2 * muzzleVelocity * sin(angleRad)) / GRAVITY;
    double maxHeight = pow(muzzleVelocity * sin(angleRad), 2) / (2 * GRAVITY);
    double actualDistance = pow(muzzleVelocity, 2) * sin(2*angleRad) / GRAVITY;


    //calculation results: feet and meter

    if (unitType == "feet" || unitType == "foot" || unitType == "Feet" || unitType == "Foot") 
    //feet result
    {
        double maxHeightFeet = maxHeight * MeterToFeet;
        double actualDistanceFeet = actualDistance * MeterToFeet;

        cout << setw(80) << setfill('=') << ' ' << endl;

        cout << "Flight Time: " << fixed << setprecision(2) <<  flightTime << " seconds "  << endl;
        cout << "Maximum height: " << fixed << setprecision(2) << maxHeightFeet << " feet"  << endl; 
        cout << "Travelled Distance "  << fixed << setprecision(1) << actualDistanceFeet << " feet" << endl;

        cout << setw(80) << setfill('=') << ' ' << endl;

        cout << "\n";

        cout << setw(80) << setfill('=') << ' ' << endl;

        if (actualDistanceFeet > targetDistance)
        {
            cout << "Travelled Distance is more than target by " << actualDistanceFeet - targetDistance << " feet. " << endl << "Outside of Range" << endl;;
        }   
        else if (actualDistanceFeet >= targetDistance - acceptedRange && actualDistanceFeet <= targetDistance + acceptedRange) 
        // if target = actual within +- 1 feet, return with "distance met"
        {
            cout << "Target Distance Met!" << endl;
        }
        else
        {
            cout << "Travelled Distance is less than target by " << targetDistance - actualDistanceFeet << " feet." << endl << "Within range" << endl;
        }

        cout << setw(80) << setfill('=') << ' ' << endl;

        cout << "\n" << endl;
    } 
    else 
    // meter result
    {
        cout << setw(80) << setfill('=') << ' ' << endl;

        cout << "Flight Time: " << fixed << setprecision(2) <<  flightTime << " seconds "  << endl;
        cout << "Maximum height: " << fixed << setprecision(2) << maxHeight << " meters"  << endl; 
        cout << "Travelled Distance "  << fixed << setprecision(1) << actualDistance << " meters" << endl;

        cout << setw(80) << setfill('=') << ' ' << endl;

        cout << "\n";

        cout << setw(80) << setfill('=') << ' ' << endl;

        if (actualDistance > targetDistance)
        {
            cout << "Travelled Distance is more than target by " << actualDistance - targetDistance << " meters. " << endl << "Outside of Range" << endl;;
        } 
        else if (actualDistance >= targetDistance - acceptedRange && actualDistance <= targetDistance + acceptedRange) 
            // if target = actual within +- 1 meter, return with "distance met"
        {
            cout << "Target Distance Met!" << endl;
        }
        else
        {
            cout << "Travelled Distance is less than target by " << targetDistance - actualDistance << " meters." << endl << "Within range" << endl;
        }

        cout << setw(80) << setfill('=') << ' ' << endl;

        cout << "\n" << endl;
    }
    
    return 0;
}