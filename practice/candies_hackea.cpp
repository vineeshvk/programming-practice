#include <bits/stdc++.h>
using namespace std;

int maxCandies(int arr[], int size, int time)
{
    int total = 0;
    for (int tm = 0; tm < time; tm++)
    {
        int i = 0;
        int max = -1;
        int pos;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] >= max)
            {
                max = arr[i];
                pos = i;
            }
        }
        total += arr[pos];
        arr[pos] /= 2;
    }
    return total;
}

int main()
{
    int t;
    cin >> t;
    for (int tests = 0; tests < t; tests++)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n, greater<int>());
        cout << maxCandies(arr, n, k) << "\n";
    }
    return 0;
}