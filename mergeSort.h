#pragma once

#include <vector>

void merge(std::vector<int>& vec, int l,int r)
{
    int i = l;
    int mid = l + (r - l) / 2;
    int j = mid + 1;
    int pos = 0;
    std::vector<int> result(r - l + 1);
    while(i <= mid || j <= r)
    {
        if(vec[i] <= vec[j])
        {
            result[pos++] = vec[i++];
        }else 
        {
            result[pos++] = vec[j++];
        }
    }
    
    while(i<=mid)
    {
        result[pos++] = vec[i++];
    }
    while(j <= r)
    {
        result[pos++] = vec[j++];
    }
    
    for (int i = l; i <= r; ++i)
    {
        vec[i] = result[i - l];
    }
    
}
void mergeSort(std::vector<int>& vec,int l,int r)
{
    if(r<=l){return;}
    int mid = l + (r - l) / 2;
    mergeSort(vec,l,mid);
    mergeSort(vec,mid+1,r);
    merge(vec,l,r);
}