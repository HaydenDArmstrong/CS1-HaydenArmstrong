#include <iostream>

int main()
{
    int i = 1;
int j = i++;
std::cout << "i is " << i;
std::cout << " and j is " << j;
    double count = 3;
    count += 2;
    std::cout << "double count is 3 + 2, which results in: " << count << std::endl;

    return 0;
}