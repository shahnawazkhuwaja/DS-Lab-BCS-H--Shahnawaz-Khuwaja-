#include <iostream>
#include <cstring>
using namespace std;

char stackArr[50];
int top = -1;

void push(char c) { stackArr[++top] = c; }
char pop() { return (top == -1) ? '\0' : stackArr[top--]; }
char peek() { return (top == -1) ? '\0' : stackArr[top]; }
bool isEmpty() { return top == -1; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

void infixToPrefix(char infix[]) {
    reverseString(infix);
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    char prefix[50];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
            prefix[j++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                prefix[j++] = pop();
            pop();
        } else {
            while (!isEmpty() && precedence(peek()) > precedence(c))
                prefix[j++] = pop();
            push(c);
        }
    }

    while (!isEmpty())
        prefix[j++] = pop();

    prefix[j] = '\0';
    reverseString(prefix);
    cout << "Prefix: " << prefix << endl;
}

int main() {
    char exp[50] = "(7+1)*8";
    cout << "Infix: " << exp << endl;
    infixToPrefix(exp);
    return 0;
}