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
    int sum;
    void dfs(TreeNode*root,int l,int r)
    {
        if(!root)
            return;
        if(root->val>=l&&root->val<=r)
            sum+=root->val;
        if(root->val>l)
            dfs(root->left,l,r);
        if(root->val<r)
            dfs(root->right,l,r);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
            sum=0;
            dfs(root,low,high);
            return sum;
    }
};
