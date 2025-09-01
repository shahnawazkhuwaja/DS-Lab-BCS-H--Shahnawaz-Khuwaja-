#include "iostream"
using namespace std;

class SafePointer {
private:
    int* ptr;

public:
    SafePointer() {
        ptr = new int;
        *ptr = 0;
    }
    ~SafePointer() {
        delete ptr;
    }
    void setValue(int value) {
        *ptr = value;
    }
    int getValue() const {
        return *ptr;
    }
    void release() {
        delete ptr;
        ptr = nullptr;
    }
};

int main() {
    int n = 5;
    SafePointer* marks = new SafePointer[n];
    cout << "Enter marks for " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        int m;
        cout << "Student " << i + 1 << ": ";
        cin >> m;
        marks[i].setValue(m);
    }
    cout << "\nMarks of students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << marks[i].getValue() << endl;
    }
    for (int i = 0; i < n; i++) {
        marks[i].release();
    }
    delete[] marks;
}