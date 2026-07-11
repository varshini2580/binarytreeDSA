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

void deleteDeepest(Node* root, Node* dbnode){
    queue<Node*> q;
    q.push(root);

    Node* curr;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(curr == dbnode){
            curr = NULL;
            delete(dbnode);
            return;
        }

        if(curr -> right){
            if(curr -> right == dbnode){
                curr -> right = NULL;
                delete(dbnode);
                return;
            }
            else{
                q.push(curr -> right);
            }
        }

        if(curr -> left){
            if(curr -> left == dbnode){
                curr -> left = NULL;
                delete(dbnode);
                return;
            }else{
                q.push(curr -> left);
            }
        }
    }
}

Node* deletion(Node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root -> left == NULL && root -> right == NULL){
        if(root -> data == key){
            delete(root);
            return NULL;
        }
        else{
            return root;
        }
    }

    queue<Node*> q;
    q.push(root);
    Node* curr;
    Node* keyNode = nullptr;


    while(!q.empty()){
        curr = q.front();
        q.pop();

        if(curr -> data == key){
            keyNode = curr;
        }

        if(curr -> left){
            q.push(curr -> left);
        }

        if(curr -> right){
            q.push(curr -> right);
        }
    }
    if(keyNode != NULL){
        int x = curr -> data;
        keyNode -> data = x;

        deleteDeepest(root, curr);
    }
      return root;
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
    root->left->right = new Node(12);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    int key = 11;
    root = deletion(root, key); 

    inorder(root);
    return 0;
}