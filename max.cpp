int max(Node* root){
    int res = root -> data;

    int lres = max(root -> left);
    int rres = max(root -> right);

    if(lres > res){
        res = lres;
    }
    if(rres > res){
        res = rres;
    }
    return res;
}