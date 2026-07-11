#include<iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int key){
        data = key;
        left = right = NULL;
    }

};

int bfs(Node* root){
    int count = 0;

    queue<Node*> q;
    q.push(root);

    count++;

    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        count++;

        if(node -> left != NULL){
            q.push(node -> left);
        }

        if(node -> right != NULL){
            q.push(node -> right);
        }
    }
    return count;
}

int getsize(Node* root){
    if(root == NULL){
        return 0;
    }

    return bfs(root);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout << "Size of the tree is: " << getsize(root) << endl;
    return 0;
}