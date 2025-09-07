#include "iostream"
using namespace std;

class SNode{
    public:
    int data;
    SNode* next;
    SNode(int val) {
        data = val;
        next = NULL;
    }
};

class DNode{
    public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList{
    SNode* head;

    public:
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        SNode* newNode = new SNode(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        SNode* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
            temp->next = newNode;
    }

    void printSingly() {
        SNode* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    DNode* convertToDoubly() {
        if (head == NULL){
            return NULL;
        }
        SNode* temp = head;
        DNode* dHead = new DNode(temp->data);
        DNode* dCurr = dHead;
        temp = temp->next;
        while (temp != NULL) {
            DNode* newNode = new DNode(temp->data);
            dCurr->next = newNode;
            newNode->prev = dCurr;
            dCurr = newNode;
            temp = temp->next;
        }
        return dHead;
    }
    SNode* convertToCircular() {
        if (head == NULL){
            return NULL;
        }
        SNode* temp = head;
        while (temp->next != NULL)
        temp = temp->next;
        temp->next = head;
        return head;
    }
};

void printDoubly(DNode* head) {
    DNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printCircular(SNode* head) {
    if (head == NULL) return;
    SNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);

    cout << "Singly Linked List: ";
    ll.printSingly();

    DNode* dHead = ll.convertToDoubly();
    cout << "Doubly Linked List: ";
    printDoubly(dHead);

    SNode* cHead = ll.convertToCircular();
    cout << "Circular Linked List: ";
    printCircular(cHead);
}