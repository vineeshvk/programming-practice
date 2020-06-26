//fenwick tree method

#include <bits/stdc++.h>
using namespace std;

long long range_sum(int tree[], int size, int range)
{
    long long sum = 0;
    while (range > 0)
    {
        sum += tree[range];
        range -= range & -range;
    }
    return sum;
}

void update_element(int tree[], int size, int index, int val)
{
    while (index <= size)
    {
        tree[index] += val;
        index += index & -index;
    }
}

void convert(int arr[], int size)
{
    int temp[size];
    memcpy(temp, arr, sizeof(int) * size);
    sort(temp, temp + size);

    for (int i = 0; i < size; i++)
        arr[i] = (lower_bound(temp, temp + size, arr[i]) - temp) + 1;
}

long long fenwick_tree(int arr[], int size)
{

    int tree[size + 1];
    memset(tree, 0, sizeof(tree));
    long long sum = 0;

    convert(arr, size);

    for (int i = size - 1; i >= 0; i--)
    {
        sum += range_sum(tree, size + 1, arr[i] - 1);
        update_element(tree, size + 1, arr[i], 1);
    }

    return sum;
}

int main()
{
    int t;
    cin >> t;
    for (int test = 0; test < t; test++)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << fenwick_tree(arr, n) << "\n";
    }
}