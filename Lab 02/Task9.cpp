#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    cout << "\nEnter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    cout << "\nMatrix in Normal Form:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int nonZero = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                nonZero++;
            }
        }
    }
    int** compressed = new int*[nonZero];
    for (int i = 0; i < nonZero; i++) {
        compressed[i] = new int[3];
    }
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                compressed[index][0] = i;
                compressed[index][1] = j;
                compressed[index][2] = matrix[i][j];
                index++;
            }
        }
    }
    cout << "\nCompressed Form (row, column, value):\n";
    for (int i = 0; i < nonZero; i++) {
        cout << compressed[i][0] << " "
             << compressed[i][1] << " "
             << compressed[i][2] << endl;
    }
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < nonZero; i++) {
        delete[] compressed[i];
    }
    delete[] compressed;
}