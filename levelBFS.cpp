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

vector<vector<int>> Levelorder(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;

    if(root == NULL){
        return {};
    }

    q.push(root);
    int currlevel = 0;
     
    while(!q.empty()){
        int len = q.size();
        ans.push_back({});
        for(int i = 0; i < len; i++){
            Node* node = q.front();
            q.pop();
            ans[currlevel].push_back(node -> data);
            
            if(node -> left != NULL){
                q.push(node -> left);
            }

            if(node -> right != NULL){
                q.push(node -> right);
            }
        }
        currlevel++;
    }

    return ans;
}

int main(){

     Node *root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);

    vector<vector<int>> res = Levelorder(root);

   for (vector<int> level : res) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;  
    }
    return 0;
}