#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int ln = m - l + 1;
    int rn = r - m;

    int left[ln], right[rn];

    for (int i = 0; i < ln; i++)
        left[i] = arr[l + i];

    for (int i = 0; i < rn; i++)
        right[i] = arr[m + 1 + i];

    int i = l, li = 0, ri = 0;
    while (li < ln && ri < rn)
    {
        bool rightGreat = left[li] < right[ri];
        arr[i++] = rightGreat ? right[ri++] : left[li++];
    }

    while (li < ln)
        arr[i++] = left[li++];
    while (ri < rn)
        arr[i++] = right[ri++];
}

void merge_sort(int arr[], int l, int r)
{
    if (r <= l)
        return;

    int m = (r + l) / 2;

    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
}
int main()
{
    int arr[] = {3, 4, 1, 2, 6, 5};
    merge_sort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}