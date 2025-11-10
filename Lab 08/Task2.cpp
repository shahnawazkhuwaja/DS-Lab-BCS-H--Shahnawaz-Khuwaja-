#include <iostream>
using namespace std;

struct Song{
    string name;
    int playCount;
    Song* left;
    Song* right;

    Song(string n, int p){
        name = n;
        playCount = p;
        left = right = NULL;
    }
};

class MusicBST{
private:
    Song* root;
    Song* insert(Song* node, string name, int playCount){
        if(node == NULL) return new Song(name, playCount);

        if(playCount < node->playCount)
            node->left = insert(node->left, name, playCount);
        else if(playCount > node->playCount)
            node->right = insert(node->right, name, playCount);
        else
            cout << "Duplicate play count not allowed!\n";
        return node;
    }
    Song* search(Song* node, int playCount){
        if(node == NULL || node->playCount == playCount)
            return node;
        if(playCount < node->playCount)
            return search(node->left, playCount);
        return search(node->right, playCount);
    }
    void inorder(Song* node){
        if(node == NULL) return;
        inorder(node->left);
        cout << node->name << " (" << node->playCount << " plays)\n";
        inorder(node->right);
    }
    void postorder(Song* node){
        if(node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->name << " (" << node->playCount << " plays)\n";
    }
    Song* findMin(Song* node){
        while(node && node->left != NULL)
            node = node->left;
        return node;
    }

    Song* deleteSong(Song* node, int playCount){
        if(node == NULL) return node;

        if(playCount < node->playCount)
            node->left = deleteSong(node->left, playCount);
        else if(playCount > node->playCount)
            node->right = deleteSong(node->right, playCount);
        else{
            if (node->left == NULL){
                Song* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == NULL){
                Song* temp = node->left;
                delete node;
                return temp;
            }
            Song* temp = findMin(node->right);
            node->name = temp->name;
            node->playCount = temp->playCount;
            node->right = deleteSong(node->right, temp->playCount);
        }
        return node;
    }

public:
    MusicBST(){
        root = NULL;
    }
    void insert(string name, int playCount){
        root = insert(root, name, playCount);
    }
    void search(int playCount){
        Song* result = search(root, playCount);
        if (result)
            cout << "Found: " << result->name << result->playCount << " plays\n";
        else
            cout << "Song not found!\n";
    }
    void displayInorder(){
        cout << "\nSongs (least to most played):\n";
        inorder(root);
    }
    void displayPostorder(){
        cout << "\nSongs removed in reverse popularity order:\n";
        postorder(root);
    }
    void deleteSong(int playCount) {
        root = deleteSong(root, playCount);
    }
};

int main() {
    MusicBST playlist;
    playlist.insert("Song 1", 10);
    playlist.insert("Song 2", 5);
    playlist.insert("Song 3", 6);
    playlist.insert("Song 4", 15);
    playlist.insert("Song 5", 7);

    cout << "Initial Playlist:\n";
    playlist.displayInorder();
    playlist.displayPostorder();

    cout << "\nSearching for song with 15 plays:\n";
    playlist.search(15);

    cout << "\nDeleting song with 10 plays\n";
    playlist.deleteSong(10);

    cout << "\nUpdated Playlist After Deletion:\n";
    playlist.displayInorder();
}