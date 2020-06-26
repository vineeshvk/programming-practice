#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++)
    {
        int NG, NM;
        cin >> NG >> NM;

        int GMonsters[NG], MMonsters[NM];

        for (int i = 0; i < NG; i++)
            cin >> GMonsters[i];
        for (int i = 0; i < NM; i++)
            cin >> MMonsters[i];

        sort(GMonsters, GMonsters + NG);
        sort(MMonsters, MMonsters + NM);

        int gi = 0, mi = 0;

        while (gi < NG && mi < NM)
        {
            if (GMonsters[gi] >= MMonsters[mi])
                mi++;
            else
                gi++;
        }
        if (gi == NG && mi == NM)
            cout << "uncertain";
        else if (gi == NG)
            cout << "MechaGodzilla";
        else
            cout << "Godzilla";
        cout << "\n";
    }
    return 0;
}