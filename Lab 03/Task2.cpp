#include "iostream"
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List{
    public:
    Node* head;
    List(){
        head = NULL;
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
            temp->next = newNode;
    }

    void printList(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* mergeTwoLists(Node* head1, Node* head2) {
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1;
        }

        if (head1->data <= head2->data) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

int main() {
    List listA, listB;

    listA.insertAtEnd(1);
    listA.insertAtEnd(3);
    listA.insertAtEnd(5);

    listB.insertAtEnd(2);
    listB.insertAtEnd(4);
    listB.insertAtEnd(6);

    cout << "List A: ";
    listA.printList(listA.head);

    cout << "List B: ";
    listB.printList(listB.head);

    Node* mergedHead = listA.mergeTwoLists(listA.head, listB.head);

    cout << "Merged List: ";
    listA.printList(mergedHead);
}