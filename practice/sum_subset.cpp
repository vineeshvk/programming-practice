/*
Find the no of subset which adds up to a given num
n = 16 from [2,4,6,10]
so its [2+4+10] == [6+10] == 16 hence 
result = 2
*/

#include <iostream>
using namespace std;

int count = 0;
int sum_subset(int ele, int arr[], int i, int size)
{
    if (i == size)
        return 0;
    if (ele > arr[i])
    {
        return sum_subset(ele - arr[i], arr, i + 1, size);
    }
    return sum_subset(ele - arr[i], arr, i + 1, size) + sum_subset(ele - arr[i], arr, i, size);
}

int main()
{
    int arr[] = {2, 4, 6, 10};
    int n = 16;
    cout << sum_subset(n, arr, 0, 4) << " " << count;
    return 0;
}