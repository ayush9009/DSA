class Solution{
    public:
    //Function to find the height of a binary tree.
    int helper(struct Node* root){
        if(root==NULL)return 0;
       return 1+max(helper(root->left),helper(root->right));
    }
    int height(struct Node* node){
        // code here 
        return helper(node);
    }
};
