#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

long long coinExchange(long long num);

map<int, long long> memory;

int main()
{
    int num;
    while (cin >> num)
        cout << coinExchange(num) << "\n";
    return 0;
}

long long coinExchange(long long num)
{
    if (num == 0)
        return 0;

    if (memory.count(num) == 0)
    {
        int n1 = num / 2;
        int n2 = num / 3;
        int n3 = num / 4;

        int total = n1 + n2 + n3;

        if (total < num)
            return num;

        long long val = coinExchange(n1) + coinExchange(n2) + coinExchange(n3);
        memory[num] = val;
    }

    return memory[num];
}
