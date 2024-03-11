#include <iostream>

using namespace std;

float add_two(float, float);

int main(void)
{
    float ans, n1=4, n2=6;
    ans = add_two(n1, n2);
    cout << "add_two with " << n1 << " and " << n2 << " as parameters = " << ans;

    return 0;
}

float add_two(float n1, float n2)
{
    return n1+n2;
}