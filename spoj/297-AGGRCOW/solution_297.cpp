#include <iostream>
#include <algorithm>

using namespace std;

void bubbleSort(int array[], int size);
int stallArrangement(int stalls[], int size, int cows);

int stallArrangement(int stalls[], int size, int cows)
{
    sort(stalls, stalls + size);
    int low = stalls[0];
    int high = stalls[size - 1];
    int mid, max = 0;
    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        int cPos = 0;
        int cowsArranged = 1;
        for (int i = 1; i < size; i++)
        {
            if (stalls[i] - stalls[cPos] >= mid)
            {
                cowsArranged++;
                cPos = i;
            }
        }
        if (cowsArranged >= cows)
        {
            max = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return max;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int size, cows;
        cin >> size >> cows;

        int stalls[size];
        for (int j = 0; j < size; j++)
            cin >> stalls[j];

        cout << stallArrangement(stalls, size, cows) << "\n";
    }

    return 0;
}

// void bubbleSort(int array[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i; j < size; j++)
//         {
//             if (array[i] > array[j])
//             {
//                 int temp = array[i];
//                 array[i] = array[j];
//                 array[j] = temp;
//             }
//         }
//     }
// }
