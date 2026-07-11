int min(Node* root){
    int res = root -> data;

    int lres = min(root -> left);
    int rres = min(root -> right);

    if(lres < res){
        res = lres;
    }
    if(rres < res){
        res = rres;
    }
    return res;
}