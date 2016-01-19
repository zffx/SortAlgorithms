#include <iostream>
void mergeArray(int a[], unsigned int begin, unsigned int mid, unsigned int end, int ret[])
{
    //a[begin]..a[mid]
    //a[mid+1]..a[end]
    unsigned int indexLeft = begin;
    unsigned int indexRight = mid + 1;
    unsigned int count = 0;
    while (indexLeft < mid && indexRight < end)
    {
        if(a[indexLeft] < a[indexRight])
        {
            ret[begin+count] = a[indexLeft];
            ++indexLeft;
        } else {
            ret[begin+count] = a[indexRight];
            ++indexRight;
        }
        ++count;
    }
    while(indexLeft< mid)
    {
        ++indexLeft;
        ++count;
        ret[begin+count] = a [indexLeft];
    }
    while(indexRight< end)
    {
        ++indexRight;
        ++count;
        ret[begin+count] = a [indexRight];
    }
}

void mergeSort(int a[], unsigned int begin, unsigned int end, int ret[])
{
    int mid = (begin + end ) / 2;
    mergeSort(a, begin, mid, ret);
    mergeSort(a, mid+1, end, ret);
    mergeArray(a, begin, mid, end, ret);
}

int main()
{
    int a[7] = {4, 1, 0, 8, 5, 6, 3};
    int ret[7] = {0, 0, 0, 0, 0, 0, 0};
    mergeSort(a, 0, 6, ret);
    for (int i = 0; i <7; ++i)
    {
        std::cout << ret[0] << '\t' << std::endl;
    }
    return 0;
}



