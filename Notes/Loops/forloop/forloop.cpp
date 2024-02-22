#include <iostream>


int main(void)
{
    for(int i=0; i<10; i++) // once loop is over, this int "i" goes away. locality is limited only to the loop when declared like this !!
    {
    std::cout << "i = " << i << std::endl;
    }

    for(int i=10; i>0; i--) // loop counts down, once it reaches 0 it stops
    {
    std::cout << "i = " << i << std::endl;
    }

   
   for (short x=1; x>0; x++)
   // infinite loop! must press control+c to break. but because it is a short instead of another datatype, will only run till 32767
    {
        std::cout << "x = " << x << std::endl;
    }
    

    return 0; 
}
