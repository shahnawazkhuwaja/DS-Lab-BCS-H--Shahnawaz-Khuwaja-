#include "iostream"
#include <string>
using namespace std;

struct Node{
    string url;
    Node* next;
};
Node* topNode = NULL;

void visitSite(string site){
    Node* newNode = new Node();
    newNode->url = site;
    newNode->next = topNode;
    topNode = newNode;
    cout << "Visited: " << site << endl;
}

void back(){
    if(topNode == NULL){
        cout << "No previous sites to go back.\n";
    }
    else{
        cout << "Going back from: " << topNode->url << endl;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
}

void currentSite(){
    if(topNode == NULL){
        cout << "No sites visited yet.\n";
    }
    else{
        cout << "Current site: " << topNode->url << endl;
    }
}

void showHistory(){
    if(topNode == NULL){
        cout << "History is empty.\n";
    }
    else{
        cout << "Browser History:\n";
        Node* temp = topNode;
        while (temp != NULL){
            cout << temp->url << endl;
            temp = temp->next;
        }
    }
}

int main(){
    visitSite("www.microsoft.com");
    visitSite("www.chess.com");
    visitSite("www.facebook.com");
    currentSite();
    back();
    currentSite();
    showHistory();
}