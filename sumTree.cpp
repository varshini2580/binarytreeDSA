int isSum(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root -> left == NULL && root -> right == NULL){
        return root -> data;
    }
    int lsum = isSum(root -> left);
    if(lsum == -1){
        return -1;
    }
    int rsum = isSum(root -> right);
    if(rsum == -1){
        return -1;
    }
    if(root -> data == lsum + rsum){
        return root -> data + lsum + rsum;
    }
    else{
        return -1;
    }
}

int main(){
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
    
    if (isSumTree(root)!=-1)
        cout << "True";
    else
        cout << "False";

    return 0;
}