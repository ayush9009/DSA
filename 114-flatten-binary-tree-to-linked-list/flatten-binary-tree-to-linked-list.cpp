/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // void helper(TreeNode* root) {
    //     if (root == NULL)
    //         return;
    //     if (root->left == NULL && root->right != NULL)
    //         return;
    //     if (root->left == NULL && root->right == NULL)
    //         return;

    //     TreeNode* lft = root->left;
    //     TreeNode* rgt = root->right;

    //     if (lft != NULL) {
    //         if (lft->left != NULL){
    //             helper(lft);
    //         }
    //     }

    //     if (rgt == NULL && lft != NULL) {
    //         root->right = lft;
    //         lft->right = NULL;
    //         root->left = NULL;
    //         return;
    //     } else if (rgt != NULL && lft != NULL) {
    //         root->right = lft;
    //         lft->right = rgt;
    //         root->left = NULL;
    //         return;
    //     }

    //     return;
    // }
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        helper(root);
    }

    void helper(TreeNode* root){
        if(root==NULL)return; //kuki hume paochna 2,3,4 vale subtree(eg:1,left)
        //ab suppose 2 se pahle koi aur subtree hota , 
        // to isliye last mai poacho bilkul
        helper(root->left);  //2 ,5 kai liye 
        // once 2->3->4 
        helper(root->right);//, 5->6

        // ye 1 kai pass hai ab,i.e 2->3->4 
        // 5->6


        TreeNode* lft = root->left;
        TreeNode* rgt = root->right;

        if(lft!=NULL){
            root->right=lft;
            root->left=NULL;

            //par kuki 2->3->4 hai 4ko 5 se attach karna 
            while(lft->right!=NULL){
                lft=lft->right;
            }

            //ab 4 milgya ,to 4 ko 5 se jodo
            lft->right=rgt;
        }
    }


};