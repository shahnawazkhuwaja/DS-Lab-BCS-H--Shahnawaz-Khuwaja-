#include "iostream"
using namespace std;

#define SIZE 5
int cqueue[SIZE];
int front = -1, rear = -1;

void enqueue(int value){
    if((front == 0 && rear == SIZE - 1) || (rear + 1 == front)){
        cout << "Queue Overflow!\n";
        return;
    }
    if(front == -1){
        front = rear = 0;
    }
    else
        rear = (rear + 1) % SIZE;
    cqueue[rear] = value;
    cout << "Enqueued: " << value << endl;
}

void dequeue(){
    if(front == -1){
        cout << "Queue Underflow!\n";
        return;
    }
    cout << "Dequeued: " << cqueue[front] << endl;
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % SIZE;
    }
}

void display(){
    if (front == -1){
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Circular Queue: ";
    int i = front;
    while(true){
        cout << cqueue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    enqueue(3);
    enqueue(5);
    enqueue(9);
    enqueue(17);
    display();
    dequeue();
    enqueue(20);
    enqueue(23);
    display();
}