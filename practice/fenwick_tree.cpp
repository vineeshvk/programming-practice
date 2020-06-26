#include <bits/stdc++.h>
using namespace std;

int addRangeFenwick(int *arr, int size, int range)
{
    int sum = 0;
    while (range > 0)
    {
        sum += arr[range];
        range -= (range & -range);
    }
    return sum;
}

int initializeFenwick(int arr[], int size, int bit[])
{

    //assigning to a fenwick tree
    for (int i = 1; i < size + 1; i++)
    {
        int pos = (i & -i) + i;

        bit[i] += arr[i - 1];

        if (pos <= size)
            bit[pos] += bit[i];
    }
}

int invCount(int arr[],int size, int bit[]){
    for(int i = size - 1; i > 0; i--){
        
    }
}

int main()
{
    int arr[] = {2, 3, 8, 6, 1};

    int bit[5 + 1];
    memset(bit, 0, sizeof(bit));

    initializeFenwick(arr, 5, bit);
    cout << addRangeFenwick(bit, 5, 5);
    return 0;
}