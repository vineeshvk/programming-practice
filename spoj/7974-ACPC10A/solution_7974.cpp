#include <iostream>

using namespace std;

void findAPGP(int x, int y, int z);

int main()
{
    while (true)
    {
        int x, y, z;
        cin >> x >> y >> z;

        if (x == 0 && y == 0 && z == 0)
            break;

        findAPGP(x, y, z);

        cout << "\n";
    }
    return 0;
}

void findAPGP(int x, int y, int z)
{
    int diff = y - x;

    if (z - y == diff)
        cout << "AP " << z + diff;
    else
        cout << "GP " << (z * y) / x;
}
