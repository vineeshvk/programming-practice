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

    cout << stack[top] << " ";

    while (visited < n && top != -1)
    {
        for (int i = 0; i < e; i++)
        {
            int first = arr[i][0];
            int second = arr[i][1];
            bool isNotVisited = !visitedNodes[second - 1];
            if (first == stack[top] && isNotVisited)
            {
                cout << second << " ";
                visited++;
                stack[++top] = second;
                visitedNodes[second - 1] = true;
            }
        }

        --top;
    }
    

    return 0;
}

/*
5 7
1 2
1 5
2 3
2 4
2 5
3 4
4 5

4 3
1 2
1 3
3 4

4 6
1 2
1 3
2 3
3 1
3 4
4 4

6 8
1 2
1 3
2 4
2 5
3 5
4 5
4 6
5 6

1 2 4 5 6 3 

5 5
1 2
1 3
1 4
2 3
3 5
*/