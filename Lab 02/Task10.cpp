#include "iostream"
using namespace std;

int main() {
    int categories;
    cout << "Enter number of categories: ";
    cin >> categories;
    int* bookCount = new int[categories];
    int** books = new int*[categories];

    for (int i = 0; i < categories; i++) {
        cout << "\nEnter number of books in category " << i + 1 << ": ";
        cin >> bookCount[i];

        books[i] = new int[bookCount[i]];
        cout << "Enter Book IDs for Category " << i + 1 << ":\n";
        for (int j = 0; j < bookCount[i]; j++) {
            cout << "Book " << j + 1 << " ID: ";
            cin >> books[i][j];
        }
    }
    int searchID;
    cout << "\nEnter Book ID to search: ";
    cin >> searchID;
    bool found = false;
    int foundCategory = -1;

    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < bookCount[i]; j++) {
            if (books[i][j] == searchID) {
                found = true;
                foundCategory = i;
                break;
            }
        }
        if (found) break;
    }
    if (found) {
        cout << "Book ID " << searchID << " is available in Category " 
             << foundCategory + 1 << ".\n";
    } else {
        cout << "Book ID " << searchID << " is NOT available in the library.\n";
    }
    for (int i = 0; i < categories; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] bookCount;
}