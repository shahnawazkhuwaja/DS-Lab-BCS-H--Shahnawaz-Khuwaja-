#include "iostream"
using namespace std;

int main() {
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;
    int* empCount = new int[departments];
    double** salaries = new double*[departments];

    for (int i = 0; i < departments; i++) {
        cout << "\nEnter number of employees in department " << i + 1 << ": ";
        cin >> empCount[i];
        salaries[i] = new double[empCount[i]];

        cout << "Enter salaries for " << empCount[i] << " employees:\n";
        for (int j = 0; j < empCount[i]; j++) {
            cout << "Employee " << j + 1 << ": ";
            cin >> salaries[i][j];
        }
    }
    cout << "\nHighest salary in each department:\n";
    for (int i = 0; i < departments; i++) {
        double maxSalary = salaries[i][0];
        for (int j = 1; j < empCount[i]; j++) {
            if (salaries[i][j] > maxSalary) {
                maxSalary = salaries[i][j];
            }
        }
        cout << "Department " << i + 1 << ": " << maxSalary << endl;
    }
    double maxAvg = -1;
    int bestDept = -1;

    for (int i = 0; i < departments; i++) {
        double sum = 0;
        for (int j = 0; j < empCount[i]; j++) {
            sum += salaries[i][j];
        }
        double avg = (empCount[i] > 0) ? sum / empCount[i] : 0;

        if (avg > maxAvg) {
            maxAvg = avg;
            bestDept = i;
        }
    }
    cout << "\nDepartment with highest average salary: Department "
         << bestDept + 1 << " (Average = " << maxAvg << ")\n";
    for (int i = 0; i < departments; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] empCount;
}