#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x1value;
    double y1value;
    double x2value;
    double y2value;
    double x3value;
    double y3value;
    double side1;
    double side2;
    double side3;
    double sideavg;
    double tobesquared;
    double area;

    cout << "Enter three points for a triangle: " << endl;
    cin >> x1value >> y1value >> x2value >> y2value >> x3value >> y3value;

    side1 = pow((x2value - x1value) * (x2value - x1value) + (y2value - y1value) * (y2value - y1value), 0.5);// side 2 and 1
    side2 = pow((x3value - x1value) * (x3value - x1value) + (y3value - y1value) * (y3value - y1value), 0.5);// side 3 and 1
    side3 = pow((x3value - x2value) * (x3value - x2value) + (y3value - y2value) * (y3value - y2value), 0.5);//side 3 and 2

    sideavg = (side1 + side2 + side3) / 2;
    tobesquared = (sideavg * (sideavg-side1) * (sideavg-side2) * (sideavg-side3));
    area = pow( tobesquared , 0.5);

    cout << "The Area of The Triangle is: "<< area << endl;
    return 0;
}