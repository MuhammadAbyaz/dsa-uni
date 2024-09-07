#include <iostream>
using namespace std;

class Vector
{
private:
    int i;
    int j;
    int k;

public:
    Vector(int first, int second, int third) : i(first), j(second), k(third)
    {
    }
    void scalar_multiplication(int scalar)
    {
        i *= scalar;
        j *= scalar;
        k *= scalar;
    }
    Vector operator+(Vector &second)
    {
        return Vector(i + second.i, j + second.j, k + second.k);
    }
    int operator-(Vector &second)
    {
        return (i * second.i) + (j * second.j) + (k * second.k);
    }
    void print()
    {
        cout << i << "i + " << j << "j + " << k << "k" << endl;
    }
};
int main()
{
    Vector A(16, -6, 7);
    Vector B(4, 2, -3);
    int x = 2;
    int y = -5;
    A.scalar_multiplication(x);
    B.scalar_multiplication(y);
    Vector C = A + B;
    C.print();
    return 0;
}