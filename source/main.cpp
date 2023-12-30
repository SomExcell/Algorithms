#include <algorithms.hpp>

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1,10,23,-2,5,9,13};
    mergeSort(vec,1,6);
    return 0;
}