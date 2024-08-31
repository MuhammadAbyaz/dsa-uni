#include <iostream>
#include <array>
using namespace std;

int *multiMatrixToSingle(int **arr, int nRows, int nCols)
{
    int *res = new int[nRows + nCols];
    int counter = 0;
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            res[i + j + counter] = arr[j][i];
        }
        counter++;
    }
    return res;
}

int main()
{
    int nRows, nCols;
    cout << "Enter number of rows: ";
    cin >> nRows;
    cout << "Enter number of colums: ";
    cin >> nCols;
    int **arr = new int *[nRows];

    for (int i = 0; i < nRows; ++i)
    {
        arr[i] = new int[nCols];
    }
    for (int i = 0; i < nRows; ++i)
    {
        cout << "Enter values for " << i + 1 << " row" << endl;
        for (int j = 0; j < nCols; ++j)
        {
            cout << "Enter value: ";
            cin >> arr[i][j];
        }
    }

    int *res = multiMatrixToSingle(arr, nRows, nCols);
    for (int i = 0; i < nRows + nCols; ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    delete[] res;
    for (int i = 0; i < nRows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}