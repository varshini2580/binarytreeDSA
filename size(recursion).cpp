#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node (int key){
        data = key;
        left = right = NULL;
    }
};

int getsize(Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return (getsize(root -> left) + 1 + getsize(root -> right) );
    }
}

int main(){
    Node * root = new Node(30);
    root -> left = new Node(20);
    root -> right = new Node(40);
    root -> left -> left = new Node(10);
    root -> left -> right = new Node(25);
    root -> right -> left = new Node(35);
    root -> right -> right = new Node(50);

    cout << "Size of the tree is: " << getsize(root) << endl;
    return 0;
}