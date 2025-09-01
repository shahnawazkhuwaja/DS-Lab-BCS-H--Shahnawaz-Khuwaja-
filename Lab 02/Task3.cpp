#include "iostream"
using namespace std;

int main(){
    int students;
    cout << "Enter number of Students: ";
    cin >> students;

    int* numcourses = new int[students];
    int** marks = new int*[students];

    for (int i = 0; i < students; i++)
    {
        cout << "Enter number of courses for students"<< i+1 <<":";
        cin >> numcourses[i];

        marks[i] = new int[numcourses[i]];
        cout << "Enter marks for " << numcourses[i] << "courses: " << endl;
        for (int j = 0; j < numcourses[i]; j++)
        {
            cout << "Courses" << j+1 << ":";
            cin >> marks[i][j];
        }
    }
    cout << "\nAverage Marks of Each Student:\n";
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < numcourses[i]; j++) {
            sum += marks[i][j];
        }
        double avg = (numcourses[i] > 0) ? (double)sum / numcourses[i] : 0;
        cout << "Student " << i + 1 << ": " << avg << endl;
    }
    for (int i = 0; i < students; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] numcourses;
}