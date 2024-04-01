#include <iostream>
using namepsace std;
template<class T>
void bubbleSort(T * array, int size) {
    bool swapped;
    for(int pass=0; pass<size; pass++) {
        swapped = false;
        // let's print array before every pass
        // TODO: comment out the following debugging info...
        //cout << "pass # " << pass << ": ";
        //printArray<T>(array, size);
        for(int i=0; i<size-1-pass; i++) {
            // sort in ascending order; check out of order?
            if (array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                swapped = true;
            }
        }
        // check if the elements are sorted; i.e. not single pair was swapped
        // let's print array after each pass; uncomment the following statement
        //printArray<T>(array, size);
        if (!swapped)
            break;
    }
}

int printArray(float array[], size_t size)
{
    for (size_t i = 0; i < count; i++)
    {
        /* code */
    }

}
int main (void)
{
    float grades[] = {12,0,93,5,67};

    bubbleSort<float>(grades, 5);


    return 0;
}