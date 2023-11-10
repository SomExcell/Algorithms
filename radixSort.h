#pragma once
#include <vector>

void radixSort(std::vector<int> &vec)
{
    int size = vec.size(),place = 1,poz = 0,value;
    std::vector<int> count(10);
    std::vector<int> positon(10);
    std::vector<int> result(size);
    while(true)
    {
        for (int i = 0; i < size; ++i)
        {
            value = vec[i]/place%10;
            ++count[value];
        } 
        for (int i = 0; i < 10; ++i)
        {
            positon[i] = poz;
            poz+=count[i];
        }
        if(count[0] == size){break;}
        for (int i = 0; i < size; ++i)
        {
            result[positon[(vec[i]/place)%10]++] = vec[i];
        }
        for (int i = 0; i < 10; ++i)
        {
            count[i] = 0,positon[i] = 0;
        }
        place*=10;
        poz = 0;
        std::swap(vec,result);
    }
    
}