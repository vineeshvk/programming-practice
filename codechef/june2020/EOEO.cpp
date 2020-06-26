#include <bits/stdc++.h>
using namespace std;




long twoFactors(long long num)
{
    long factors = 0;
    while (num % 2 == 0)
    {
        num /= 2;
        factors++;
    }
    return factors;
}

long long tenSeries(long long num)
{
    long long result = (num / 10) * 5;
    if (num % 10 != 0)
    {
        for (int i = 2; i <= num % 10; i += 2)
            result++;
    }
    return result;
}

long long jerryWins(long long TS)
{
    if (TS % 2 != 0)
        return tenSeries(TS);
    else
    {
        long long count = 0;

        long p = twoFactors(TS);
        int i = 2;

        long power = pow(2, p + 1);

        long long val = power;
        while (val < TS)
        {
            count++;
            val = power * i++;
        }
        return count;
    }
}

int main()
{
    int test = 1;
    cin >> test;
    for (int t = 0; t < test; t++)
    {
        long long TS;
        cin >> TS;
        long long jerry = jerryWins(TS);
        cout << jerry << "\n";
    }

    return 0;
}

long long jerryWinsBrute(long long TS)
{
    if (TS % 2 != 0)
    {
        int count = 0;
        for (int i = 2; i < TS; i += 2)
            count++;
        return count;
    }
    else
    {
        int count = 0;
        for (int i = 2; i <= TS; i += 2)
        {
            long long temp = TS;
            int it = i;
            while (it % 2 == 0 && temp % 2 == 0)
            {
                it /= 2;
                temp /= 2;
            }

            if (it % 2 == 0)
                count++;
        }
        return count;
    }
}