#include <iostream>
#include <math.h>

using namespace std;

int trailingZeros(int num);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        cout << trailingZeros(num) << "\n";
    }
}

int trailingZeros(int num)
{
    int zeros = 0;
    int times = 1;
    int fives = pow(5, times);
    while (fives <= num)
    {
        zeros += num / fives;
        times++;
        fives = pow(5, times);
    }
    return zeros;
}
