#include <iostream>
#include <cstring>
using namespace std;

char stackArr[50];
int top = -1;

void push(char c) { stackArr[++top] = c; }
char pop() { return (top == -1) ? '\0' : stackArr[top--]; }
char peek() { return (top == -1) ? '\0' : stackArr[top]; }
bool isEmpty() { return top == -1; }

int precedence(char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char infix[]){
    char postfix[50];
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
            postfix[j++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            pop();
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while (!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';
    cout << "Postfix: " << postfix << endl;
}

int main() {
    char exp[50] = "4+(1*5)-7";
    cout << "Infix: " << exp << endl;
    infixToPostfix(exp);
}