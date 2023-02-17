/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode * root){
        if(root==NULL)return 0;
        int l=helper(root->left);
        int r=helper(root->right);
        if(l==-1 || r==-1)return -1;
        if(abs(l-r)>1)return -1;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
    //     if(root==NULL)
    //         return true;
    //     int lh=height(root->left);
    //     int rh=height(root->right);
    //     return (abs(lh-rh)<1||abs(lh-rh)==1)&&isBalanced(root->left)&&isBalanced(root->right);
    if(root==NULL)return true;
    if(helper(root)==-1)return false;
    return true;
    }
    // int height(TreeNode* root)
    // {
        // if(root==NULL)
        //     return 0;
        // else
        //     return max(height(root->left),height(root->right))+1;
        
    // }
};
