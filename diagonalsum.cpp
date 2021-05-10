#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int matrix[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += matrix[i][i];
    }

    cout << "sum of diagonal elements of given matrix is " << sum << endl;
    return 0;
}