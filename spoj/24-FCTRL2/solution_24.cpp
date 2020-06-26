#include <iostream>
// array method for large numbers
using namespace std;

void factorial(int);
int multiplyUsingArray(int x, int fact[], int size);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        factorial(num);
        cout << "\n";
    }
}

void factorial(int num)
{
    int fact[500];

    fact[0] = 1;
    int size = 1;

    for (int i = 1; i <= num; i++)
        size = multiplyUsingArray(i, fact, size);

    for (int i = size - 1; i >= 0; i--)
        cout << fact[i];
}

int multiplyUsingArray(int x, int *fact, int size)
{
    int carry = 0;

    for (int i = 0; i < size; i++)
    {
        int prod = fact[i] * x + carry;
        fact[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry != 0)
    {
        fact[size] = carry % 10;
        carry = carry / 10;
        size++;
    }
    return size;
}
