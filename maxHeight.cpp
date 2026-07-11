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

int Levelorder(Node* root){
    if(root == NULL){
        return 0;
    }

   queue<Node* > q;
   q.push(root);

   int depth = 0;
   while(!q.empty()){
        int len = q.size();
        for(int i = 0; i < len; i++){
            Node* node = q.front();
            q.pop();

            if(node -> left != NULL){
                q.push(node -> left);
            }

            if(node -> right != NULL){
                q.push(node -> right);
            }
        }
        depth++;
   }
   return depth;
}

int main(){
  Node *root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);
    
    cout << Levelorder(root);

    return 0;
}