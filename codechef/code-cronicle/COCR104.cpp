#include <iostream>
using namespace std;

long long marker_count(long long a, long long b, long long L, long long R)
{
    long long val = 0, count = 0;
    int x = 1;
    while (val < R)
    {
        val = (a + b) * x;
        x++;
    }

    int i = x, j = x;

    do
    {
        val = a * i + b * j;
        i == j ? j-- : i--;
        abcdefghijklmnopqrstuvwxxyzabcdefghijklmnopqrstvwxyzabcdefghijklmnopqrstuvwxyzabcdefhgijkmnopqrstuvw
    } while (val > R);

    i == j ? i++ : j++;

    return i * 2 - (i != j ? 1 : 0);
}

int main()
{
    int test;
    cin >> test;

    for (int t = 0; t < test; t++) 
    {
        long long a, b, L, R;
        cin >> a >> b >> L >> R;
        cout << marker_count(a, b, L, R) << "\n";
    }
    return 0;
}