#include <iostream>
#include <array>
#include <random>
using std::cout;

template<size_t T>
void bubble_sort(std::array<int,T> &array)
{
    bool sorted = false;            // sort flag
    for (size_t i=0;i<array.size();i++)
    {
        sorted = true;
        for (size_t k=0;k<array.size()-1;k++)
        {

            if(array[k]>array[k+1])
            {
                std::swap(array[k],array[k+1]);
                sorted = false;
            }
        }
        if (sorted)
            return;
    }
}

int main()
{
    std::array<int,15> array{3,71,53,12,5,20,201,95,51,63,13,6,53,135,36};
    cout<<"Current array:\n";
    for(auto it: array)
    {
        cout<<it<<" ";
    }  
    bubble_sort(array);
    cout<<"\nCurrent array:\n";
    for(auto it: array)
    {
        cout<<it<<" ";
    }
}
