#include <iostream>
#include <algorithm>
using namespace std;

string decryptMessage(string message, int col)
{
    int i = 0;
    int row = message.size() / col;

    string msArray[row];
    string dMessage = "";

    int pos = 0;
    for (int i = 0; i < row; i++)
    {
        string rowM = message.substr(pos, col);
        if (i % 2 != 0)
            reverse(rowM.begin(), rowM.end());

        msArray[i] = rowM;
        pos += col;
    }

    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
            dMessage += msArray[j][i];

    return dMessage;
}

int main()
{
    while (true)
    {
        int col;
        string message;
        cin >> col;
        if (col == 0)
            break;
        cin >> message;
        cout << decryptMessage(message, col) << "\n";
    }
    return 0;
}
//hthelerloe