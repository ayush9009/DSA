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
    // int maxiPath(TreeNode *root,int &maxi){
    //     if(root==NULL)
    //         return 0;
    //     int lt=max(0,maxiPath(root->left,maxi));
    //     int rt=max(0,maxiPath(root->right,maxi));
    //     maxi=max(maxi,(lt+rt+root->val));
    //     return root->val+max(lt,rt);
    // }
    int maxiPath(TreeNode*root,int &maxi){
        if(root==NULL)return 0;
        auto ls=max(0,maxiPath(root->left,maxi));
        auto rs=max(0,maxiPath(root->right,maxi)); //yaha max isliye le rai agr kisi child ne negatice returnkarato0lo
        maxi=max(maxi,root->val+ls+rs);
        return root->val+max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
       int maxi=INT_MIN;
       maxiPath(root,maxi);
       return maxi;
    }
};
