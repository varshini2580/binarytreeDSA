#include<iostream>
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

int Finddiameter(Node* root){
   int diameter = 0;
   maxHeight(root, diameter);
   return diameter;
} 

int maxHeight(Node* root, int& diameter){
    if(root == NULL){
        return -1;
    }

    int lh = maxHeight(root -> left, diameter);
    int rh = maxHeight(root -> right, diameter);
    diameter = max(diameter, lh + rh);

    return max(lh, rh) + 1;


}

int main(){
    Node *root = new Node(12);
        root->left = new Node(8);
        root->right = new Node(18);
        root->left->left = new Node(5);
        root->left->right = new Node(11);
        
        cout << Finddiameter(root);
    
        return 0;
}