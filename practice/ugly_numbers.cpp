#include <iostream>
#include <math.h>

using namespace std;

int uglyNumbers(int n)
{
    int count = 0, num = 1, div = 2, temp = num;
    while (count != n)
    {
        if (temp == 1)
        {
            temp = ++num;
            count++;
            div = 2;
            continue;
        }

        if (temp % div != 0)
        {
            if (div == 5)
            {
                temp = ++num;
                div = 2;
            }
            else
                div = div == 3 ? 5 : 3;
        }
        else
            temp /= div;
    }
    return --num;
}

// 1,2,3,4,5,6,8,9 divided only by 2, 3 or 5
int uglyNumbersDP(int n)
{
    int uglyNum[n];
    uglyNum[0] = 1;

    int i2 = 0, i3 = 0, i5 = 0;
    int m2 = 2, m3 = 3, m5 = 5;

    for (int i = 1; i < n; i++)
    {
        uglyNum[i] = min(m2, min(m3, m5));

        if (uglyNum[i] == m2)
            m2 = uglyNum[++i2] * 2;
        if (uglyNum[i] == m3)
            m3 = uglyNum[++i3] * 3;
        if (uglyNum[i] == m5)
            m5 = uglyNum[++i5] * 5;


    }

    return uglyNum[n - 1];
}

int main()
{
    while (true)
    {

        int n;
        cin >> n;
        // cout << uglyNumbers(n) << "\n";
        cout << uglyNumbersDP(n) << "\n";
    }
}