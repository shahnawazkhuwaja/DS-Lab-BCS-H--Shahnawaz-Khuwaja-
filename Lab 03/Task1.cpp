#include "iostream"
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head = tail = NULL;
    }

    void insertAtFirst(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void printLL(){
        Node* temp = head;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool Palindrome(){
        if (head == NULL || head->next == NULL){
            return true;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* prev = NULL;
        Node* curr = slow;
        Node* next = NULL;

        while (curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        Node* first = head;
        Node* second = prev;

        while (second != NULL){
            if (first->data != second->data){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};

int main(){
    List ll;
    ll.insertAtFirst(1);
    ll.insertAtFirst(2);
    ll.insertAtFirst(3);
    ll.insertAtFirst(2);
    ll.insertAtFirst(1);

    ll.printLL();

    if (ll.Palindrome()){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }    
}
