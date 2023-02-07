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
    int helper(TreeNode* root,long long prev,int sum){
        if(root==NULL)return 0;
        long long cur=prev+root->val;
        return (cur==sum)+helper(root->left,cur,sum)+helper(root->right,cur,sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        return helper(root,0,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};
