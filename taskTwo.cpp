#include <iostream>
#include <array>
using namespace std;
const int creditHrs = 3;

void calculateGpa(float **arr, int nStudents)
{
    for (int i = 0; i < nStudents; ++i)
    {
        int total = 0;
        for (int j = 0; j < (sizeof(&arr[i]) / sizeof(&arr[i][0])); ++j)
        {
            total += (arr[i][j] * creditHrs);
        }
        cout << "GPA of " << i + 1 << " student: " << total / ((sizeof(&arr[i]) / sizeof(&arr[i][0])) * creditHrs) << endl;
    }
}
int main()
{
    int nStudents;
    cout << "Enter number of students: ";
    cin >> nStudents;
    float **arr = new float *[nStudents];
    for (int i = 0; i < nStudents; ++i)
    {
        int nSubjects;
        cout << "Enter number of subjects for " << i + 1 << " student: ";
        cin >> nSubjects;
        arr[i] = new float[nSubjects];
        for (int j = 0; j < nSubjects; ++j)
        {
            cout << "Enter GPA for " << j + 1 << " subject for " << i + 1 << " student: ";
            cin >> arr[i][j];
        }
    }
    calculateGpa(arr, nStudents);
    for (int i = 0; i < nStudents; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}