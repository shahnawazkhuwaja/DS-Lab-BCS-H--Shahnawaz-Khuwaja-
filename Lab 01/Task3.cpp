#include "iostream"
using namespace std;

class Box {
private:
    int* value;

public:
    Box() {
        value = new int;
        *value = 0;
        cout << "Box Created, Value = " << *value << endl;
    }

    Box(int v) {
        value = new int(v);
        cout << "Box Created, Value = " << *value << endl;
    }

    Box(const Box& other) {
        value = new int(*other.value);
        cout << "Box Copied (Deep Copy), Value = " << *value << endl;
    }

    Box& operator=(const Box& other) {
        if (this != &other) {
            delete value;
            value = new int(*other.value);
            cout << "Box Assigned (Deep Copy), Value = " << *value << endl;
        }
        return *this;
    }

    void setValue(int v) {
        *value = v;
    }

    void printValue() {
        cout << "Value = " << *value << endl;
    }

    ~Box() {
        cout << "Box Destroyed, Value = " << *value << endl;
        delete value;
    }
};

int main() {
    Box b1(10);
    Box b2 = b1;
    b2.setValue(20);
    cout << "b1: "; b1.printValue();
    cout << "b2: "; b2.printValue();

    Box b3(30);
    b3 = b1;
    b3.setValue(40);
    cout << "b1: "; b1.printValue();
    cout << "b3: "; b3.printValue();

    Box b4(50);
    Box b5 = b4;
    b5.setValue(60);
    cout << "b4: "; b4.printValue();
    cout << "b5: "; b5.printValue();
 return 0;
}