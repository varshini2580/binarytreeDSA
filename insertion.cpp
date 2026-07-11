#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int key){
        data = key;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int key){
    if(root == NULL){
       root = new Node(key);
       return root;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        if(node -> left != NULL){
            q.push(node -> left);
        }
        else{
            node -> left = new Node(key);
            return root;
        }
        if(node -> right != NULL){
            q.push(node -> right);
        }
        else{
            node -> right = new Node(key);
            return root;
        }
    }

}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

int main(){
    
    Node* root = new Node(10);
    root->left = new Node(11);
  	root->right = new Node(9);
    root->left->left = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(8);
  
    int key = 12;
    root = insert(root, key);
    inorder(root);



    return 0;
}