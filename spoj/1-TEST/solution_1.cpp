#include <iostream>
using namespace std;

    int main()
    {
        while (true)
        {
            int val;
            cin >> val;
            if (val == 42)
                return 0;
            cout << val << "\n";
        }
    }