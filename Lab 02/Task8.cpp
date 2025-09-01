#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter number of readings per day: ";
    cin >> m;
    double** temp = new double*[n];
    for (int i = 0; i < n; i++) {
        temp[i] = new double[m];
    }

    cout << "\nEnter temperature readings:\n";
    for (int i = 0; i < n; i++) {
        cout << "Day " << i + 1 << ":\n";
        for (int j = 0; j < m; j++) {
            cout << "  Reading " << j + 1 << ": ";
            cin >> temp[i][j];
        }
    }
    double* avg = new double[n];
    int hottestDay = 0, coldestDay = 0;

    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) {
            sum += temp[i][j];
        }
        avg[i] = sum / m;
        if (avg[i] > avg[hottestDay]) hottestDay = i;
        if (avg[i] < avg[coldestDay]) coldestDay = i;
    }
    cout << "\nDaily Average Temperatures:\n";
    for (int i = 0; i < n; i++) {
        cout << "Day " << i + 1 << ": " << avg[i] << endl;
    }

    cout << "\nHottest Day: Day " << hottestDay + 1 << " (Avg Temp = " << avg[hottestDay] << ")\n";
    cout << "Coldest Day: Day " << coldestDay + 1 << " (Avg Temp = " << avg[coldestDay] << ")\n";
    for (int i = 0; i < n; i++) {
        delete[] temp[i];
    }
    delete[] temp;
    delete[] avg;
}