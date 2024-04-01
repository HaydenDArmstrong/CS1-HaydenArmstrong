#include <iostream>

using namespace std;

void doubleArray1 (int array[], size_t size);
void doubleArray2(int array[], int *array2, size_t size);
void printArray(int array[], size_t size);

int main(void)
{
    int some_array[4] = {4,4,3,2};
    size_t size = 4;
    int doubled[4];

    doubleArray1(some_array, size);
    printArray(some_array, size);

    doubleArray2(some_array, doubled, size);
    printArray(some_array, size);


    return 0;
}

void doubleArray1(int array[], size_t size)
{
    for (size_t i=0; i<size; i++)
    {
        array[i] = array[i]*2;
    }
    cout << endl;
}

void printArray(int array[], size_t size)
{
    cout << endl;
    for(size_t i=0; i<size; i++)
    {
        cout << array[i] << ", ";
    }
}