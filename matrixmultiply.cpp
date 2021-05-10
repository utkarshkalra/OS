#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row1, col1;
    cout << "enter matrix 1's row and col" << endl;
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

    int row2, col2;
    cout << "enter matrix 2's row and col" << endl;
    cin >> row2 >> col2;

    if (col1 != row2)
    {
        cout << "column of first matrix isn't equal to rows in second matrix" << endl;
        return 0;
    }

    cout << "enter Matrix 2" << endl;
    int matrix2[row1][col1];
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cin >> matrix2[i][j];
        }
    }

    int res[row1][col2] = {0};

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < col1; k++)
            {
                res[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << "sum is : " << endl;

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}