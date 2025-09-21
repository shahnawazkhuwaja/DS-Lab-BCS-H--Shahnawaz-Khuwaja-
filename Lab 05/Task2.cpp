#include <iostream>
using namespace std;

void printNumbers(int n) {
    if (n == 0) return;
    cout << n << " ";
    printNumbers(n - 1);
}

void functionB(int n);

void functionA(int n) {
    if (n <= 0) return; 
    cout << "A: " << n << endl;
    functionB(n - 1);
}

void functionB(int n) {
    if (n <= 0) return; 
    cout << "B: " << n << endl;
    functionA(n - 1);
}

int main() {
    cout << "Direct recursion: ";
    printNumbers(5);
    cout << endl;

    cout << "\nIndirect recursion:\n";
    functionA(5);
}