#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row1, col1;
    cout << "enter row and col" << endl;
    cin >> row1 >> col1;
    cout << "enter Matrix 1" << endl;
    int matrix1[row1][col1];
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "enter Matrix 2" << endl;
    int matrix2[row1][col1];
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cin >> matrix2[i][j];
        }
    }

    int res[row1][col1];

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "sum is : " << endl;

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}