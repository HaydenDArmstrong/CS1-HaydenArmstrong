#include <iostream>
#include <fstream>

using namespace std;

template <class T1>
void swap_two(&T1, &T2);

int main (void)
{
    return 0;
}


template <class T1>
void swap_two(T1 &n1, T2 &n2)
{
    T1 temp = n1;
    n1 = n2;
    n2 = temp;
}