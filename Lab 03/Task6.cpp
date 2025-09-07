#include "iostream"
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    Node(int val){
        data = val;
        next = NULL;
        child = NULL;
    }
};

class MultiLevelList{
    public:
    Node* head;
    MultiLevelList(){
        head = NULL;
    }

    void insertAtEnd(Node*& head, int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    Node* flatten(Node* head){
        if (head == NULL) return NULL;

        Node* curr = head;
        while (curr != NULL){
            if (curr->child != NULL){
                Node* nextNode = curr->next;
                Node* childHead = flatten(curr->child);
                curr->next = childHead;
                Node* temp = childHead;
                while (temp->next != NULL)
                    temp = temp->next;
                    temp->next = nextNode;
                    curr->child = NULL;
            }
            curr = curr->next;
        }
        return head;
    }

    void printList(Node* head){
        Node* temp = head;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    MultiLevelList ml;
    ml.insertAtEnd(ml.head, 1);
    ml.insertAtEnd(ml.head, 2);
    ml.insertAtEnd(ml.head, 3);
    ml.insertAtEnd(ml.head->next->child, 4);
    ml.insertAtEnd(ml.head->next->child, 5);

    cout << "Original List:" << endl;
    cout << "1 -> 2 -> 3, and 2 has child 4 -> 5" << endl;

    Node* flatHead = ml.flatten(ml.head);

    cout << "Flattened List: ";
    ml.printList(flatHead);
}