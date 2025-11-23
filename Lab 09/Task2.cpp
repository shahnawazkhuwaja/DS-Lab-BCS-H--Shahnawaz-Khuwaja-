#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) {
        key = k;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node* n){
    if (!n) return 0;
    return n->height;
}

int getBalance(Node* n){
    if (!n) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

int max(int a, int b){
    return (a > b) ? a : b;
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node* insertNode(Node* node, int key){
    if (!node) return new Node(key);
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else
        node->right = insertNode(node->right, key);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void rangeQuery(Node* root, int X, int Y){
    if (!root) return;
    if (root->key > X)
        rangeQuery(root->left, X, Y);
    if (root->key >= X && root->key <= Y)
        cout << root->key << " ";
    if (root->key < Y)
        rangeQuery(root->right, X, Y);
}

int main(){
    Node* root = NULL;

    int prices[] = {1212, 222, 300, 750, 1800, 1200, 1100};
    int n = sizeof(prices) / sizeof(prices[0]);

    for (int i = 0; i < n; i++)
        root = insertNode(root, prices[i]);

    int X, Y;
    cout << "Enter X: ";
    cin >> X;
    cout << "Enter Y: ";
    cin >> Y;

    cout << "Prices between " << X << " and " << Y << ": ";
    rangeQuery(root, X, Y);
    cout << endl;
}