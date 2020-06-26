#include <iostream>

using namespace std;

int revNum(int);

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        int revX = revNum(x);
        int revY = revNum(y);
        cout << revNum(revX + revY) << "\n";
    }
}

int revNum(int num)
{

    int rev = 0;

    while (num != 0)
    {
        int digit = num % 10;
        rev = (rev * 10) + digit;
        num /= 10;
    }

    return rev;
}