#include <bits/stdc++.h>
using namespace std;

bool is_special(int arr[], int size)
{
    sort(arr, arr + size);
    int diff = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != diff && diff != -1)
            return false;
        if (diff == -1)
            diff = arr[i];
    }
    return true;
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
        cout << (is_special(arr, n) ? "YES" : "NO")
             << "\n";
    }
}