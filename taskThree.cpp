#include <iostream>
#include <vector>
using namespace std;

class Vector
{
private:
    vector<int> data;
    int dimensions;

public:
    Vector(int d) : dimensions(d)
    {
    }
    void input_vector()
    {
        for (int i = 0; i < dimensions; ++i)
        {
            cout << "Enter " << i + 1 << " value: ";
            int input;
            cin >> input;
            data.push_back(input);
        }
    }
    Vector scalar_multiplication(int scalar)
    {
        Vector res(dimensions);
        for (int i = 0; i < dimensions; ++i)
        {
            res.data.push_back(data[i] * scalar);
        }
        return res;
    }
    Vector operator+(Vector &second)
    {
        if (dimensions != second.dimensions)
        {
            throw invalid_argument("Vector addition is not posible");
        }
        Vector res(dimensions);
        for (int i = 0; i < dimensions; ++i)
        {
            res.data.push_back(data[i] + second.data[i]);
        }
        return res;
    }
    int operator*(Vector &second)
    {
        if (dimensions != second.dimensions)
        {
            throw invalid_argument("Vector multiplication is not posible");
        }
        int res = 0;
        for (int i = 0; i < dimensions; ++i)
        {
            res += data[i] * second.data[i];
        }
        return res;
    }
    void print()
    {
        char unit_vector = 'i';
        for (int i = 0; i < dimensions; ++i)
        {
            cout << data[i] << unit_vector << " ";
            unit_vector++;
        }
        cout << endl;
    }
};
int main()
{
    Vector A(3);
    Vector B(3);
    A.input_vector();
    B.input_vector();
    int x = 2;
    int y = -5;
    Vector C = A.scalar_multiplication(x);
    Vector D = B.scalar_multiplication(y);
    Vector F = C + D;
    F.print();
    int dot_product = A * B;
    cout << dot_product;
    return 0;
}