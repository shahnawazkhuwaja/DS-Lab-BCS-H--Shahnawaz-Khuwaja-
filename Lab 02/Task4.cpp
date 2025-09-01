#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of months to track expenses: ";
    cin >> n;
    double* expenses = new double[n];
    cout << "\nEnter expenses for " << n << " months:\n";
    for (int i = 0; i < n; i++) {
        cout << "Month " << i + 1 << ": ";
        cin >> expenses[i];
    }
    char choice;
    cout << "\nDo you want to add more months(y/n): ";
    cin >> choice;
    if (choice == 'y'||choice == 'Y') {
        int extra;
        cout << "How many extra months";
        cin >> extra;
        int newSize = n+extra;
        double* newExpenses = new double[newSize];

        for (int i = 0; i < n; i++) {
            newExpenses[i] = expenses[i];
        }
        cout << "\nEnter expenses for the new " << extra << " months:\n";
        for (int i = n; i < newSize; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> newExpenses[i];
        }
        delete[] expenses;
        expenses = newExpenses;
        n = newSize;
    }
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += expenses[i];
    }
    double avg = (n > 0) ? total / n : 0;
    cout << "\nMonthly Expenses:\n";
    for (int i = 0; i < n; i++) {
        cout << "Month " << i + 1 << ": " << expenses[i] << endl;
    }
    cout << "\nTotal Expenses = " << total << endl;
    cout << "Average Expenses = " << avg << endl;

    delete[] expenses;
}