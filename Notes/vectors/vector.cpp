#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<double> nums = {1.2, 3, 4, 5, 6.6};
    vector<int> int_nums;
    
    cout << nums[0] << " or using at() " << nums.at(0) <<
    " Or using .front() " << nums.front() << endl;

     cout << "Max vector size on this computer " << nums.max_size() << endl;

     for (int i=0; i<10; i++)
     {
        int_nums.push_back(i*2);
     }
     for (auto it=int_nums.begin())
     {
        cout << *it << endl;
     }

    return 0;

    }