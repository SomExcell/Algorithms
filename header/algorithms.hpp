#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

void insertSort(std::vector<int> &vec)
{
	int key,i;
	for(int j = 1;j < vec.size(); ++j)
	{
		key = vec[j];
		i = j - 1;
		while(i >= 0 && vec[i] < key)
		{
			vec[i+1] = vec[i];
			i = i - 1;
		}
		vec[i+1] = key;
	}
}

void selectionSort(std::vector<int> &vec)
{
	int size = vec.size();
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = i + 1; j < size; ++j)
		{
			if(vec[i] < vec[j])
			{
				std::swap(vec[i],vec[j]);
			}
		}
	}
}

void merge(std::vector<int>& vec, int l,int r)
{
    int i = l;
    int mid = l + (r - l) / 2;
    int j = mid + 1;
    int pos = 0;
    std::vector<int> result(r - l + 1);
    while(i <= mid && j <= r)
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

void mergeSort(std::vector<int>& vec,int start,int end)
{
    if(end<=start){return;}
    int mid = start + (end - start) / 2;
    mergeSort(vec,start,mid);
    mergeSort(vec,mid+1,end);
    merge(vec,start,end);
}

int partition(std::vector<int> &vec,int left,int right)
{
    int pivot  = vec[left + rand()%(right - left + 1)];
    while(left<=right)
    {
        while(vec[left]<pivot){++left;}
        while(vec[right] >pivot){--right;}
        if(left<=right)
        {
            std::swap(vec[left],vec[right]);
            ++left;
            --right;
        }
    }
    return left;
}

void quickSort(std::vector<int> &vec,int start,int end)
{
    if(start>=end){return;}
    int rightStart = partition(vec,start,end);
    quickSort(vec,start,rightStart-1);
    quickSort(vec,rightStart,end);
}

void radixSort(std::vector<int>& arr) {
    int maxDigit = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxDigit / exp > 0; exp *= 10) {
        std::vector<int> sortedArr(arr.size());
        std::vector<int> count(10);
        for (int i = 0; i < arr.size(); ++i) {
            count[(arr[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }
        for (int i = arr.size() - 1; i >= 0; --i) {
            sortedArr[--count[(arr[i] / exp) % 10]] = arr[i];
        }
        arr = sortedArr;
    }
}