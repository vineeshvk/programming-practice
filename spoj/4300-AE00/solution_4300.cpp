#include <iostream>
#include <math.h>

using namespace std;

int factors(int num);
int rectangleCount(int num);

int rectangleCount(int num)
{
    int total = 0;
    for (int i = 2; i <= num; i++)
        total += factors(i);
    return num + total;
}

int factors(int num)
{
        int count = 0;
        for (int i = 2; i <= sqrt(num); i++)
            if (num % i == 0)
                count++;

    return count;
}

int main()
{
    int num;
    cin >> num;
    cout << rectangleCount(num) << "\n";
    return 0;
}
