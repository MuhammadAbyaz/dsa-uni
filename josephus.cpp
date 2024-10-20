#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    int i = 1;
    int ans = 0;

    while (i <= n)
    {
        ans = (ans + k) % i;
        i++;
    }
    return ans + 1;
}

int main()
{
    int n;
    int k;
    cout << "Enter total number of persons: ";
    cin >> n;
    cout << "Enter skips: ";
    cin >> k;
    cout << "The topper is " << josephus(n, k) << endl;
    return 0;
}