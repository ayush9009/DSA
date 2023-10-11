int height(Node *r){
    if(r==NULL)
        return 0;
    int lh=height(r->left);
    int rh=height(r->right);
    return max(lh,rh)+1;
}
bool isBalanced(Node *root)
{
    //  Your Code here
    if(root==NULL||(root->left==NULL&&root->right==NULL))
        return true;
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)<=1)
        return isBalanced(root->left)&isBalanced(root->right);
    else
        return false;
}
