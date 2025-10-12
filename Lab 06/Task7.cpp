#include "iostream"
using namespace std;

struct Process{
    int id;
    int priority;
};

Process queueArr[10];
Process stackArr[10];
int front = -1, rear = -1, top = -1;

void enqueue(Process p){
    if (rear == 9) cout << "Queue full!\n";
    else {
        if (front == -1) front = 0;
        queueArr[++rear] = p;
    }
}

Process dequeue(){
    Process p = {-1, -1};
    if (front == -1 || front > rear) cout << "Queue empty!\n";
    else p = queueArr[front++];
    return p;
}

void push(Process p){
    if (top == 9) cout << "Stack full!\n";
    else stackArr[++top] = p;
}

Process pop(){
    Process p = {-1, -1};
    if (top == -1) cout << "Stack empty!\n";
    else p = stackArr[top--];
    return p;
}

int main(){
    enqueue({3, 4});
    enqueue({1, 3});
    enqueue({2, 1});
    enqueue({6, 6});

    cout << "Jobs arrived:\n";
    for (int i = front; i <= rear; i++)
        cout << "Process " << queueArr[i].id << " | Priority " << queueArr[i].priority << endl;
    while (front <= rear) {
        Process p = dequeue();
        if (p.priority >= 3)
            push(p);
    }

    cout << "\nExecuting High Priority Jobs:\n";
    while (top != -1) {
        Process p = pop();
        cout << "Executing Process " << p.id << " | Priority " << p.priority << endl;
    }
    cout << "\nDemonstrated use of Queue and Stack\n";
}