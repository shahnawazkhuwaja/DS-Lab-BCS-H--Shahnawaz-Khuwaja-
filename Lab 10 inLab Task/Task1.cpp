#include "iostream"
using namespace std;

struct Node{
    string patient;
    int priority;
    int arrival;
    Node* next;

    Node(string pat, int pri, int arr) : patient(pat), priority(pri), arrival(arr), next(nullptr) {}
};

class PriorityQueue{
    private:
    Node* front;
    int counter;

    public:
    PriorityQueue() : front(nullptr), counter(0) {}

    ~PriorityQueue(){
        while(front){
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool higher(Node*a, Node*b){
        if(a->priority != b->priority){
            return a->priority > b->priority;
        }
        return a->arrival < b->arrival;
    }

    void insert(string pat, int pri){
        Node* newNode = new Node(pat, pri, counter++);

        if(!front || higher(newNode, front)){
            newNode->next = front;
            front = newNode;
        }
        else{
            Node* current = front;
            while(current->next && !higher(newNode, current->next)){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    void Remove(){
        if(!front){
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Treating: " << front->patient << endl;
        front = front->next;
        delete temp;
    }
    string peek(){
        if(!front){
            cout << "Queue is empty" << endl;
            return "";
        }
        return front->patient;
    }

    void update(string pat, int newPri){
        if(!front){
            return;
        }
        Node* current = front;
        Node* prev = nullptr;

        while(current && current->patient != pat){
            prev = current;
            current = current->next;
        }
        if(!current){
            cout << "Patient not found" << endl;
            return;
        }
        if(prev){
            prev->next = current->next;
        }
        else{
            front = current->next;
        }
        current->priority = newPri;
        current->next = nullptr;

        if(!front || higher(current, front)){
            current->next = front;
            front = current;
        }
        else{
            Node* temp = front;
            while(temp->next && !higher(current, temp->next)){
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    void printQueue(){
        if(!front){
            cout << "Queue is empty" << endl;
            return;
        }
        Node* current = front;
        while(current){
            cout << "(" << current->patient << ", " << current->priority << ")" << endl;
            current = current->next;
        }
        cout << endl;
    }
};


int main(){
    PriorityQueue p1;
    p1.insert("Shahnawaz", 3);
    p1.insert("Asad", 7);
    p1.insert("Lucky", 1);
    p1.insert("Ali", 4);
    p1.insert("Hussain", 5);
    p1.printQueue();

    p1.update("Ali", 9);
    p1.printQueue();
    p1.Remove();
    p1.printQueue();
}
