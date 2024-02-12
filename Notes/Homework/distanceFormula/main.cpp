 #include <cmath>
#include <iostream>

using namespace std;

    int main()
    {
        double x1Given;
        double y1Given;
        double x2Given;
        double y2Given;
        double xterms;
        double yterms;
        double insideSQRT;
        double finalProduct;

        cout << "enter x1 and y1: " << endl;
        cin >> x1Given >> y1Given;
        cout << "enter x2 and y2: " << endl;
        cin >> x2Given >> y2Given;

        xterms = (x2Given - x1Given);
        xterms = pow(xterms, 2);

        yterms = (y2Given - y1Given);
        yterms = pow(yterms, 2);

        insideSQRT = (xterms + yterms);

        finalProduct = pow(insideSQRT, 0.5);

        cout << "The Distance between the two points is: " << finalProduct << endl;


        return 0;
    
    }