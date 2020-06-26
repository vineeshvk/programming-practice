//segment tree for sum of range
#include <bits/stdc++.h>
using namespace std;

int range_sum(int tree[], int root, int lPos, int rPos, int lRange, int rRange)
{
    if (lPos >= lRange && rPos <= rRange)
    {
        return tree[root];
    }
    else if (rPos < lRange || lPos > rRange)
    {
        return 0;
    }
    else
    {
        int mid = (lPos + rPos) / 2;

        int left = range_sum(tree, root * 2 + 1, lPos, mid, lRange, rRange);
        int right = range_sum(tree, root * 2 + 2, mid + 1, rPos, lRange, rRange);
        return left + right;
    }
}

void segment_tree(int arr[], int tree[], int l, int r, int pos)
{

    if (l == r)
    {
        tree[pos] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    int lPos = 2 * pos + 1;
    int rPos = 2 * pos + 2;

    segment_tree(arr, tree, l, mid, lPos);
    segment_tree(arr, tree, mid + 1, r, rPos);

    tree[pos] = tree[lPos] + tree[rPos];
}

int main()
{
    int arr[] = {1, 2, 5, 6, 7, 9};
    int size = 6;
    int treeSize = 2;
    while (treeSize < size)
        treeSize *= 2;
    treeSize *= 2;

    int tree[treeSize];
    memset(tree, 0, sizeof(tree));

    segment_tree(arr, tree, 0, size - 1, 0);

    for (int i = 0; i < treeSize; i++)
        cout << tree[i] << " ";

    int sum = range_sum(tree, 0, 0, size - 1, 2, 4);
    cout << "\n"
         << sum;
    return 0;
}
