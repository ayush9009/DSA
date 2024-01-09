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
    void traverse(TreeNode *root,vector<int>&result)
    {
        if(root!=NULL)
        {
            if(root->left==NULL && root->right==NULL)
                result.push_back(root->val);
            traverse(root->left,result);
            traverse(root->right,result);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>result;
        vector<int>ans;
        traverse(root1,result);
        traverse(root2,ans);
        if(result==ans)
            return true;
        else
            return false;
    }
};
