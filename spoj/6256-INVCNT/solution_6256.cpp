//merge sort method
#include <bits/stdc++.h>

using namespace std;

void merge_arr(long long arr[], long long l, long long m, long long r, long long *inv)
{
    long long ln = m - l + 1;
    long long rn = r - m;

    long long left[ln], right[rn];

    for (long long i = 0; i < ln; i++)
        left[i] = arr[l + i];
    for (long long i = 0; i < rn; i++)
        right[i] = arr[m + i + 1];

    long long li = 0, ri = 0, i = l;
    while (li < ln && ri < rn)
    {
        bool leftGreat = left[li] > right[ri];
        if (leftGreat)
            *inv += ln - li;

        arr[i++] = !leftGreat ? left[li++] : right[ri++];
    }

    while (li < ln)
        arr[i++] = left[li++];
    while (ri < rn)
        arr[i++] = right[ri++];
}

void merge_sort(long long arr[], long long l, long long r, long long *inv)
{
    if (r <= l)
        return;

    long long m = (l + r) / 2;

    merge_sort(arr, l, m, inv);
    merge_sort(arr, m + 1, r, inv);

    merge_arr(arr, l, m, r, inv);
}

int main()
{
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++)
    {
        long long n;
        cin >> n;
        long long arr[n];

        for (long long j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        long long inversion = 0;
        merge_sort(arr, 0, n - 1, &inversion);
        cout << inversion << "\n";
    }
    return 0;
}
