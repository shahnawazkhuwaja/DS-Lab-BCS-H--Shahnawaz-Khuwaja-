#include "iostream"
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
    public:
    CircularList() {
        head = NULL;
    }

    void createCircle(int N){
        head = new Node(1);
        Node* prev = head;
        for (int i=2; i<=N; i++){
            Node* newNode = new Node(i);
            prev->next = newNode;
            prev = newNode;
        }
        prev->next = head;
    }

    int josephus(int k){
        Node* curr = head;
        Node* prev = NULL;

        while (curr->next != curr){
            for (int i = 1; i < k; i++) {
                prev = curr;
                curr = curr->next;
            }
            cout << "Eliminated: " << curr->data << endl;
            prev->next = curr->next;
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        return curr->data;
    }
};

int main() {
    int N = 7, k = 3;
    CircularList cl;
    cl.createCircle(N);

    int survivor = cl.josephus(k);
    cout << "Survivor: " << survivor << endl;
}
