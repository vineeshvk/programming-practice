#include <iostream>

using namespace std;

int main()
{
    long long i = 1;
    long long sum = 0;
    long long n = 1000000000;
    while (i * 3 < n)
    {
        int five = i * 5;
        int three = i * 3;

        if (five < n)
            sum += five;
        
        if (three % 5 != 0)
            sum += three;
        
        i++;
    }
    cout << sum << "\n";

    return 0;
}