#include <iostream>
using namespace std;

struct Person{
    string name;
    Person* mother;
    Person* father;
    Person(string n) : name(n), mother(NULL), father(NULL) {}
};

class FamilyTree{
private:
    Person* root;

public:
    FamilyTree(){
        root = NULL;
    }
    void createFamily(){
        root = new Person("Child");
        root->mother = new Person("Mother\n");
        root->father = new Person("Father\n");
        root->mother->mother = new Person("Grandmother Maternal\n");
        root->mother->father = new Person("Grandfather Maternal\n");
        root->father->mother = new Person("Grandmother Paternal\n");
        root->father->father = new Person("Grandfather Paternal\n");
    }

    void displayRoot(){
        if(root) cout << "Root (youngest person): " << root->name << endl;
    }

    void displayLeafNodes(Person* node){
        if (node == NULL) return;

        if (node->mother == NULL && node->father == NULL)
            cout << node->name << " ";

        displayLeafNodes(node->mother);
        displayLeafNodes(node->father);
    }

    int height(Person* node){
        if (node == NULL) return 0;
        int leftHeight = height(node->mother);
        int rightHeight = height(node->father);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }

    void displayLevels(Person* node, int level){
        if (node == NULL) return;
        cout << node->name << " Level " << level << endl;
        displayLevels(node->mother, level + 1);
        displayLevels(node->father, level + 1);
    }

    void displayFamilyInfo(){
        displayRoot();
        cout << "\nLeaf Nodes (ancestors with no known parents): ";
        displayLeafNodes(root);
        cout << "\n\nHeight of Tree: " << height(root) << endl;
        cout << "\nLevel of each member:\n";
        displayLevels(root, 1);
    }
};

int main() {
    FamilyTree tree;
    tree.createFamily();
    tree.displayFamilyInfo();
    return 0;
}
