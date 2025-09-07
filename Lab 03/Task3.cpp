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
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* reverseinKGroup(Node* head, int k){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;

        Node* temp = head;
        for(int i=0; i< k; i++){
            if (temp==NULL){
                return head;
            }
            temp = temp->next;
        }

        while (curr != NULL && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next != NULL){
            head->next = reverseinKGroup(next, k);
        }
        return prev;
    }

    void reverseinKGroup(int k){
        head = reverseinKGroup(head, k);
    }

};

int main(){
    List ll;
    ll.insertAtFirst(1);
    ll.insertAtFirst(2);
    ll.insertAtFirst(3);
    ll.insertAtFirst(4);
    ll.insertAtFirst(5);
    ll.insertAtFirst(6);
    ll.insertAtFirst(7);

    ll.reverseinKGroup(3);
    ll.printLL();
}