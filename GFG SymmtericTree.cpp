class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool helper(struct Node* p,struct Node* q){
        if(p==NULL && q==NULL)return true;
        if(p==NULL || q==NULL)return p==q;
        if(p->data!=q->data)return false;
        return helper(p->left , q->right) && helper(p->right , q->left);
    }
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL)return true;
	    return helper(root->left,root->right);
    }
};
