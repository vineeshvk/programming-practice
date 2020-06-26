#include <bits/stdc++.h>
using namespace std;

int main()
{

    int test;
    cin >> test;
    for (int t = 0; t < test; t++)
    {
        string word;
        cin >> word;

 
        int size = word.size();
        int mid = (size) / 2;
 
        bool odd = size % 2 != 0 ? 1 : 0;

        long long  sum = 0;
        for (int i = 0; i < mid; i++)
        {
            sum += (int)word[i];
            sum -= (int)word[mid + i + odd];
        }
        cout << (sum == 0 ? "YES" : "NO") <<"\n";
    }
    return 0;
}