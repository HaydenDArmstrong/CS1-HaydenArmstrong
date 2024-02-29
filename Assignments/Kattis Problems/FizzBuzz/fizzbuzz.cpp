#include <iostream>
#include <cmath>

int main()
{
    int n;
    int x;
    int y;
    std::string ans;
    std::cin >> x >> y >> n;

    for (int i=1; i<=n; i++)
    {
        if(i%x == 0 && i%y == 0)
        {
            ans = "FizzBuzz";
        }
        else if (i%x == 0)
        {
            ans = "Fizz";
        }
        else if (i%y == 0)
        {
            ans = "Buzz";
        }
        else {
            ans = std::to_string(i);
        }

        std::cout << ans << std::endl;
    }

    return 0;
}