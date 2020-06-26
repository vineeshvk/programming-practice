#include <iostream>
using namespace std;

string canArrangeTrucks(int *trucks, int size)
{
    int top = -1;
    int nextEntry = 1;
    int stack[size];
    int i = 0;
    while (nextEntry <= size && i < size)
    {
        if (trucks[i] == nextEntry)
        {
            nextEntry++;
            i++;
        }
        else
        {
            if (top != -1 && stack[top] == nextEntry)
            {
                nextEntry++;
                top--;
            }
            else if (top != -1 && stack[top] < trucks[i])
                return "no";

            else
            {
                stack[++top] = trucks[i];
                i++;
            }
        }
    }
    for (i = top; i >= 0; i--)
    {
        if (nextEntry != stack[top--])
        {
            return "no";
        }
        nextEntry++;
    }
    return ((nextEntry - 1) != size) ? "no" : "yes";
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        int trucks[n];
        for (int i = 0; i < n; i++)
            cin >> trucks[i];
        cout << canArrangeTrucks(trucks, n) << "\n";
    }

    return 0;
}