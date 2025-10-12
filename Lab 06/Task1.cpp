#include "iostream"
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

void push(int value){
    if(top == MAX-1){
        cout << "Overflow!\n";
    }
    else{
        stack[++top] = value;
    }
}

void pop(){
    if(top == -1){
        cout << "Underflow!\n";
    }
    else{
        cout << "Popped element: " << stack[top--] << endl;
    }
}

void peek(){
    if(top == -1){
        cout << "Stack is empty.\n";
    }
    else{
        cout << "Top element: " << stack[top] << endl;
    }
}

void display(){
    if(top == -1){
        cout << "Stack is empty.\n";
    }
    else{
        cout << "Stack: ";
        for(int i = top; i >= 0; i--){
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    push(2);
    push(7);
    push(10);
    display();
    peek();
    pop();
    display();
}
