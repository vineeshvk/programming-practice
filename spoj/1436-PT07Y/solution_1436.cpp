#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int arr[e][2];
    int stack[n], top = -1;

    bool visitedNodes[n];
    memset(visitedNodes, false, n);

    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }

    stack[++top] = arr[0][0];
    visitedNodes[stack[top] - 1] = true;
    int visited = 1;

    while (visited < n && top != -1)
    {
        for (int i = 0; i < e; i++)
        {
            int first = arr[i][0];
            int second = arr[i][1];
            bool isNotVisited = !visitedNodes[second - 1];
            if (first == stack[top] && isNotVisited)
            {
                visited++;
                stack[++top] = second;
                visitedNodes[second - 1] = true;
            }
        }
        top--;
    }

    if ((n - 1) == e && visited == n)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}