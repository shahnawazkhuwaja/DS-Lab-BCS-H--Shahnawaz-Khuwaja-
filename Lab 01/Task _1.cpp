#include "iostream"
using namespace std;

class BankAccount {
private:
    double *balance;

public:
    BankAccount(double amount) {
        balance = new double(amount);
        *balance = amount;
        cout << "Account Created, Your Balance is: " << *balance << endl;
    }

    BankAccount() {
        balance = new double;
        *balance = 0;
        cout << "Account Created" << endl;
    }

    BankAccount(const BankAccount& other) {
        balance = new double(*other.balance);
    }

    BankAccount& operator=(const BankAccount& other) {
        if (this != &other) {
            delete balance;
            balance = new double(*other.balance);
        }
        return *this;
    }

    void withdraw(double amount) {
        *balance -= amount;
        cout << amount << " has been withdrawn." << endl;
    }

    void Deposit(double amount) {
        *balance += amount;
        cout << amount << " has been deposited." << endl;
    }

    void PrintBalance() {
        cout << "Your Balance is: " << *balance << endl;
    }

    ~BankAccount() {
        delete balance;
    }
};

int main() {
    BankAccount account1;
    BankAccount account2(1000);
    BankAccount account3;
    account2 = account3;
    account3.Deposit(200);
    account3.PrintBalance();
    account2.PrintBalance();
}
