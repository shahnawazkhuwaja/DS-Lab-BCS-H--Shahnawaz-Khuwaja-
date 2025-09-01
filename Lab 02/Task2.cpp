#include "iostream"
using namespace std;

int main(){
    int rows, cols;
    cout << "Enter rows(benches): ";
    cin >> rows;
    cout << "Enter Columns(seats per bench): ";
    cin >> cols;

    int** seats = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        seats[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            seats[i][j] = 0;
        }
        
    }

    cout << "Seat Chart (0: empty and 1: filled):" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }

    char choice;
    int r, c;
    while (true)
    {
        cout << "Enter bench(row) number: ";
        cin >> r;
        cout << "Enter seat(column) number: ";
        cin >> c;
        if (r < 0 || r >= rows || c < 0 || c >=cols)
        {
            cout << "Invalid input" << endl;
        }
        else{
            seats[r][c] = 1;
        }
        cout << "Do you want to occupy another seat(y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y'){
            break;
        }
        
    }
    cout << "Seating Chart: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] seats[i];
    }
    delete[] seats;
}