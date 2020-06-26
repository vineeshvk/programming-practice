#include <bits/stdc++.h>
using namespace std;

int longestPathDFS(int arr[][2], int nodes, int root = -1)
{

    bool fromMax = root != -1;

    int stack[nodes], top = -1;

    bool visitedNodes[nodes];
    memset(visitedNodes, false, nodes);

    stack[++top] = arr[0][0];

    if (fromMax)
        stack[top] = root;

    visitedNodes[stack[top] - 1] = true;
    int visited = 1;
    int max = -1, maxPos = -1;

    while (visited < nodes && top != -1)
    {
        int i = 0;
        while (i < nodes - 1)
        {
            int first = arr[i][0];
            int second = arr[i][1];

            if (first == stack[top] && !visitedNodes[second - 1])
            {
                visited++;
                stack[++top] = second;
                visitedNodes[second - 1] = true;
                i = 0;
            }
            else if (second == stack[top] && !visitedNodes[first - 1])
            {
                visited++;
                stack[++top] = first;
                visitedNodes[first - 1] = true;
                i = 0;
            }
            else
                i++;
        }
        if (maxPos < top)
        {
            maxPos = top;
            max = stack[top];
        }

        --top;
    }

    return fromMax ? maxPos : max;
}

int main()
{
    int nodes;
    cin >> nodes;

    int arr[nodes - 1][2];

    for (int i = 0; i < nodes - 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }

    int maxVal = longestPathDFS(arr, nodes);
    int maxPath = longestPathDFS(arr, nodes, maxVal);
    cout << maxPath;

    return 0;
}