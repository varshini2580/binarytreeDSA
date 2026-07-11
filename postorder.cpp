#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int k){
        data = k;
        left = right = NULL;
    }
};

void postorder(Node* node, vector<int>& ans){
    postorder(node->left, ans);
    postorder(node->right, ans);
    ans.push_back(node->data);
}

int main(){
    vector<int> ans;
    Node* root = new Node(20);
    Node* root->left = new Node(10);
    Node* root->right = new Node(30);
    Node* root->left-> left = new Node(5);
    Node* root->left-> right = new Node(15);
    Node* root->right-> right = new Node(25);
    postorder(root, ans);
    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}