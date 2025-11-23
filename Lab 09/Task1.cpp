#include "iostream"
#include <string>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k){
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

void printStatus(string action, int key, Node* node, string rotation){
    cout << action << " " << key << endl;
    cout << "Height: " << getHeight(node) << endl;
    cout << "Rotation: " << rotation << endl;
    cout << "Balance Factor Root: " << getBalance(node) << endl;
    cout << endl;
}

Node* rightRotate(Node* y, string& rotation){
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    rotation = "Right Rotation";
    return x;
}

Node* leftRotate(Node* x, string& rotation){
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    rotation = "Left Rotation";
    return y;
}

Node* insertNode(Node* node, int key, string& rotation){
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insertNode(node->left, key, rotation);
    else
        node->right = insertNode(node->right, key, rotation);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node, rotation);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node, rotation);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left, rotation);
        return rightRotate(node, rotation);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right, rotation);
        return leftRotate(node, rotation);
    }

    return node;
}

Node* minValueNode(Node* n){
    Node* cur = n;
    while (cur->left) cur = cur->left;
    return cur;
}

Node* deleteNode(Node* root, int key, string& rotation){
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key, rotation);
    else if (key > root->key)
        root->right = deleteNode(root->right, key, rotation);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key, rotation);
        }
    }

    if (!root) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root, rotation);

    if (balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left, rotation);
        return rightRotate(root, rotation);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root, rotation);

    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right, rotation);
        return leftRotate(root, rotation);
    }

    return root;
}

int main(){
    Node* root = NULL;
    int inserts[] = {45, 35, 10, 25, 20, 22, 40};
    int deletes[] = {10, 20, 22};

    for(int key : inserts){
        string rotation = "None";
        root = insertNode(root, key, rotation);
        printStatus("Inserted", key, root, rotation);
    }

    for(int key : deletes){
        string rotation = "None";
        root = deleteNode(root, key, rotation);
        printStatus("Deleted", key, root, rotation);
    }
}