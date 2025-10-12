#include "iostream"
using namespace std;

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value){
    if(rear == SIZE - 1){
        cout << "Queue is full!\n";
    }
    else{
        if(front == -1)
            front = 0;
        queue[++rear] = value;
        cout << "Enqueued: " << value << endl;
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        cout << "Queue is empty!\n";
    }
    else{
        cout << "Dequeued: " << queue[front++] << endl;
    }
}

void displayQueue(){
    if (front == -1 || front > rear){
        cout << "Queue is empty!\n";
    }
    else{
        cout << "Queue: ";
        for(int i = front; i <= rear; i++){
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

void checkStatus(){
    if(rear == SIZE - 1){
        cout << "Queue is full.\n";
    }
    else if(front == -1 || front > rear){
        cout << "Queue is empty.\n";
    }
    else{
        cout << "Queue has space.\n";
    }
}

int main() {
    enqueue(4);
    enqueue(9);
    enqueue(15);
    displayQueue();
    dequeue();
    displayQueue();
    checkStatus();
}