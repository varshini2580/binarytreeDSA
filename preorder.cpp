#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};

void preorder(Node* node, vector<int> res){
    if(node == NULL){
        return;
    }

    res.push_back(node -> data);
    preorder(node->left, res);
    preorder(node->right, res);
}

int main(){
    vector<int> res;
    Node* root = new Node(20);
    Node* root->left = new Node(10);
    Node* root->right = new Node(30);
    Node* root->left-> left = new Node(5);
    Node* root->left-> right = new Node(15);
    Node* root->right-> right = new Node(25);

    preorder(root, res);
    for(int i : res){
        cout << i << " ";
    }
    return 0;
}