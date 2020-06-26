#include <iostream>

using namespace std;

int maxHotness(int men[], int women[], int size);
void sortArray(int array[], int size);

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        int men[n], women[n];
        for (int j = 0; j < n; j++)
            cin >> men[j];

        for (int j = 0; j < n; j++)
            cin >> women[j];

        cout << maxHotness(men, women, n) << "\n";
    }
    return 0;
}

int maxHotness(int men[], int women[], int size)
{
    sortArray(men, size);
    sortArray(women, size);

    int total = 0;

    for (int i = 0; i < size; i++)
        total += men[i] * women[i];

    return total;
}

void sortArray(int array[], int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
