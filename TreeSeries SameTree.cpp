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
    // bool SAME(TreeNode *p,TreeNode *q)
    // {
    //     if(p==NULL&&q==NULL)
    //         return true;
    //     else if(p==NULL||q==NULL)
    //         return false;
    //     if(p->val==q->val)
    //     {
    //         return SAME(p->left,q->left) && SAME(p->right,q->right);
    //     }
    //     else
    //         return false;
    // }
    bool helper(TreeNode *p,TreeNode*q){
        if(p==NULL && q==NULL)return true;
        if(p==NULL || q==NULL || (p->val!=q->val))return false;

        bool l=helper(p->left,q->left);
        bool r=helper(p->right,q->right);

        return l&&r;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
       // return SAME(p,q); 
        // if(p==NULL && q==NULL)return true;
        // else if(p==NULL || q==NULL)return false;
        // if(p->val==q->val){
        //     return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        // }
        // else
        //     return false;
        return helper(p,q);
    }
};
