#include <iostream>
#include <string>
using namespace std;

struct Node {
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

int h(Node* n){
    if (!n) return 0;
    return n->height;
}

int bal(Node* n){
    if (!n) return 0;
    return h(n->left) - h(n->right);
}

int mx(int a, int b){
    return a > b ? a : b;
}

Node* rightRotate(Node* y, string& r){
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = mx(h(y->left), h(y->right)) + 1;
    x->height = mx(h(x->left), h(x->right)) + 1;
    r = "Right Rotation";
    return x;
}

Node* leftRotate(Node* x, string& r){
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = mx(h(x->left), h(x->right)) + 1;
    y->height = mx(h(y->left), h(y->right)) + 1;
    r = "Left Rotation";
    return y;
}

Node* insertNode(Node* root, int key, string& rotation){
    if (!root) return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key, rotation);
    else
        root->right = insertNode(root->right, key, rotation);

    root->height = 1 + mx(h(root->left), h(root->right));

    int balance = bal(root);

    if (balance > 1 && key < root->left->key)
        return rightRotate(root, rotation);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root, rotation);

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left, rotation);
        return rightRotate(root, rotation);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right, rotation);
        return leftRotate(root, rotation);
    }

    return root;
}

Node* minValue(Node* n){
    while (n->left) n = n->left;
    return n;
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
            if (!temp){
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValue(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key, rotation);
        }
    }

    if (!root) return root;

    root->height = 1 + mx(h(root->left), h(root->right));

    int balance = bal(root);

    if (balance > 1 && bal(root->left) >= 0)
        return rightRotate(root, rotation);

    if (balance > 1 && bal(root->left) < 0) {
        root->left = leftRotate(root->left, rotation);
        return rightRotate(root, rotation);
    }

    if (balance < -1 && bal(root->right) <= 0)
        return leftRotate(root, rotation);

    if (balance < -1 && bal(root->right) > 0) {
        root->right = rightRotate(root->right, rotation);
        return leftRotate(root, rotation);
    }

    return root;
}

int highestSeverity(Node* root){
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->key;
}

void printStatus(string op, int key, Node* root, string rotation){
    cout << op << " " << key << endl;
    cout << "Tree Height: " << h(root) << endl;
    cout << "Rotation: " << rotation << endl;
    cout << "Highest Severity: " << highestSeverity(root) << endl;
    cout << endl;
}

int main(){
    Node* root = NULL;

    int inserts[] = {50, 40, 60, 30, 45, 70, 20};
    int deletes[] = {40, 70};

    for(int v : inserts){
        string rotation = "None";
        root = insertNode(root, v, rotation);
        printStatus("Inserted", v, root, rotation);
    }

    for(int v : deletes){
        string rotation = "None";
        root = deleteNode(root, v, rotation);
        printStatus("Deleted", v, root, rotation);
    }
}