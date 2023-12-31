#include <algorithms.hpp>

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1,10,23,-2,5,9,13};
    std::vector<int> vec1 = {1,-2,5,9,5,3,2,1,1,0};
    //mergeSort(vec,1,6);
    //quickSort(vec,0,6);
    radixSort(vec);
    return 0;
}