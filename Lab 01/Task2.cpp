#include "iostream"
using namespace std;

class Exam {
private:
    string* name, *date;
    int* score;

public:
    Exam() {
        name = new string;
        date = new string;
        score = new int;
    }

    Exam(string name, string date, int score) {
        this->name = new string(name);
        this->date = new string(date);
        this->score = new int(score);
    }

    void SettingDetails(string n, string d, int s) {
        *name = n;
        *date = d;
        *score = s;
    }

    void DisplayDetails() {
        cout << "Name: " << *name << endl;
        cout << "Date: " << *date << endl;
        cout << "Score: " << *score << endl;
    }

    ~Exam() {
        delete name;
        delete date;
        delete score;
    }
};

int main() {
    Exam e1;  
    e1.SettingDetails("OOP Exam", "23-May-2025", 85);
    e1.DisplayDetails();

    Exam e2("Calculus Exam", "4-June-2025", 82);
    e2.DisplayDetails();

return 0;
}