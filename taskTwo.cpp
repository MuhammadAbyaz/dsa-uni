#include <iostream>
#include <array>
#include <iomanip>
using namespace std;
const float creditHrs = 3.0;

void calculateGpa(float **arr, int nStudents, int subjects[])
{
    for (int i = 0; i < nStudents; ++i)
    {
        float total = 0.0;
        float totalCreditHrs = 0.0;
        for (int j = 0; j < subjects[i]; ++j)
        {
            total += (arr[i][j] * creditHrs);
            totalCreditHrs += creditHrs;
        }
        float gpa = total / totalCreditHrs;
        cout << "GPA of " << i + 1 << " student: " << fixed << setprecision(2) << gpa << endl;
    }
}
int main()
{
    int nStudents;
    cout << "Enter number of students: ";
    cin >> nStudents;
    int subjects[nStudents];
    float **arr = new float *[nStudents];
    for (int i = 0; i < nStudents; ++i)
    {
        int nSubjects;
        cout << "Enter number of subjects for " << i + 1 << " student: ";
        cin >> nSubjects;
        arr[i] = new float[nSubjects];
        subjects[i] = nSubjects;
        for (int j = 0; j < nSubjects; ++j)
        {
            cout << "Enter GPA for " << j + 1 << " subject for " << i + 1 << " student: ";
            cin >> arr[i][j];
        }
    }
    calculateGpa(arr, nStudents, subjects);
    for (int i = 0; i < nStudents; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}