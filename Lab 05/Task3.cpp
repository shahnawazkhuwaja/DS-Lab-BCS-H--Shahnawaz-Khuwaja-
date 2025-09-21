#include <iostream>
using namespace std;

int sumTail(int n, int total = 0) {
    if (n == 0) return total; 
    return sumTail(n - 1, total + n);
}

int sumNonTail(int n) {
    if (n == 0) return 0;
    return n + sumNonTail(n - 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Sum using tail recursion = " << sumTail(n) << endl;
    cout << "Sum using non-tail recursion = " << sumNonTail(n) << endl;

    cout << "\nDifference:\n";
    cout << "- Tail recursion: recursion happens last → compiler can optimize calls (less stack).\n";
    cout << "- Non-tail recursion: work happens AFTER recursion → deeper stack usage.\n";
}