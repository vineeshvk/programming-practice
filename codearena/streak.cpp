#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;
        if (num % 21 == 0)
        {
            cout << "The streak is broken!\n";
            continue;
        }
        string str = to_string(num);
        bool two = false;
        bool broke = false;

        for (char c : str)
        {
            if (two && c == '1')
            {
                cout << "The streak is broken!\n";
                broke = true;
                break;
            }
            two = false;
            if (c == '2')
                two = true;
        }
        if(!broke)
            cout<< "The streak lives still in our heart!"<<"\n";
    }
}