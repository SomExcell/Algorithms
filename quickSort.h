int partition(vector<int> &vec,int left,int right)
{
    int pivot  = vec[left + rand()%(right - left + 1)];
    while(left<=right)
    {
        while(vec[left]<pivot){++left;}
        while(vec[right] >pivot){--right;}
        if(left<=right)
        {
            swap(vec[left],vec[right]);
            ++left;
            --right;
        }
    }
    return left;
}

void quickSort(vector<int> &vec,int start,int end)
{
    if(start>=end){return;}
    int rightStart = partition(vec,start,end);
    quickSort(vec,start,rightStart-1);
    quickSort(vec,rightStart,end);
}
