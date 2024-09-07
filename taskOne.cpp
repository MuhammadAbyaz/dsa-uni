#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
private:
    vector<vector<int>> data;
    int nRows;
    int nCols;

public:
    Matrix(int r, int c, bool flag = true) : nRows(r), nCols(c)
    {
        if (flag)
        {
            input_matrix();
        }
        else
        {
            for (int i = 0; i < r; ++i)
            {
                data.push_back(vector<int>(c, 0));
            }
        }
    }
    pair<int, int> get_rows_cols()
    {
        return pair<int, int>(nRows, nCols);
    }
    void input_matrix()
    {
        for (int i = 0; i < nRows; ++i)
        {
            vector<int> row;
            for (int j = 0; j < nCols; ++j)
            {
                int input;
                cout << "Enter data for " << i + 1 << " row and " << j + 1 << " column: ";
                cin >> input;
                row.push_back(input);
            }
            data.push_back(row);
        }
    }
    void print()
    {
        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < nCols; ++j)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    int binary_search(int target)
    {
        for (int i = 0; i < nRows; ++i)
        {
            if (data[i][nCols - 1] > target)
            {
                int lo = 0;
                int hi = nCols - 1;
                while (hi > lo)
                {
                    int mid = lo + (hi - lo) / 2;
                    if (data[i][mid] == target)
                    {
                        return mid;
                    }
                    if (data[i][mid] > target)
                    {
                        hi = mid - 1;
                    }
                    else
                    {
                        lo = mid + 1;
                    }
                }
                return -1;
            }
        }
    }
    Matrix operator+(Matrix &second)
    {
        if (get_rows_cols().first != second.get_rows_cols().first || get_rows_cols().second != second.get_rows_cols().second)
        {
            throw invalid_argument("Addition is not possible");
        }
        Matrix result(get_rows_cols().first, get_rows_cols().second, false);
        for (int i = 0; i < get_rows_cols().first; ++i)
        {
            for (int j = 0; j < get_rows_cols().second; ++j)
            {
                result.data[i][j] = data[i][j] + second.data[i][j];
            }
        }
        return result;
    }
    Matrix operator*(Matrix &another)
    {
        if (get_rows_cols().second != another.get_rows_cols().first)
        {
            throw invalid_argument("Addition is not possible");
        }
        Matrix result(get_rows_cols().first, another.get_rows_cols().second, false);
        for (int i = 0; i < get_rows_cols().first; ++i)
        {
            for (int j = 0; j < another.get_rows_cols().second; ++j)
            {
                for (int k = 0; k < another.get_rows_cols().first; ++k)
                {
                    result.data[i][j] += data[i][k] * data[k][j];
                }
            }
        }
        return result;
    }
    void scalar_multiplication(int scalar)
    {
        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < nCols; ++j)
            {
                data[i][j] *= scalar;
            }
        }
    }
    Matrix create_transpose()
    {
        Matrix res(nCols, nRows, false);
        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < nCols; ++j)
            {
                res.data[j][i] = data[i][j];
            }
        }
        return res;
    }
};

int main()
{
    int rows1;
    int cols1;
    int rows2;
    int cols2;
    cout << "Enter number of rows for first: ";
    cin >> rows1;
    cout << "Enter number of cols for first: ";
    cin >> cols1;
    Matrix m1(rows1, cols1);
    cout << "Enter number of rows for second: ";
    cin >> rows2;
    cout << "Enter number of cols for second: ";
    cin >> cols2;
    Matrix m2(rows2, cols2);
    Matrix m3 = m1 + m2;
    Matrix m4 = m1 * m2;
    m3.print();
    m4.print();
    m1.scalar_multiplication(2);
    Matrix m5 = m1.create_transpose();
    m5.print();
    return 0;
}