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
    // //MORIS TRAVERSAL (AYUSH-SHARMA,SECTION-B,ROLL_NO-66)
    // vector<int> inorderTraversal(TreeNode* root) {
    //    vector<int>inorder;
    //    TreeNode *cur=root;
    //    while(cur!=NULL){
    //        if(cur->left==NULL){
    //            inorder.push_back(cur->val);
    //            cur=cur->right;
    //        }else{
    //            TreeNode *prev=cur->left;
    //            while(prev->right && prev->right!=cur){
    //                prev=prev->right;
    //            }
    //            if(prev->right==NULL){
    //                prev->right=cur;
    //                cur=cur->left;
    //            }else{
    //                prev->right=NULL;
    //                inorder.push_back(cur->val);
    //                cur=cur->right;
    //            }
    //        }
    //    }
    //    return inorder;
    // }
    //  vector<int>result;
    //  void helper(TreeNode* root){
    //      if(root!=NULL){
    //          helper(root->left);
    //          result.push_back(root->val);
    //          helper(root->right);
    //      }
    //  }
    //  vector<int> inorderTraversal(TreeNode* root) {
    //      helper(root);
    //      return result;
    //  }
    // MORRIS TRAVERSAL
    vector < int > inorderTraversal(TreeNode * root) {
  vector < int > inorder;

  TreeNode * cur = root;
  while (cur != NULL) {
    if (cur -> left == NULL) {
      inorder.push_back(cur -> data);
      cur = cur -> right;
    } else {
      TreeNode * prev = cur -> left;
      while (prev -> right != NULL && prev -> right != cur) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = cur;
        cur = cur -> left;
      } else {
        prev -> right = NULL;
        inorder.push_back(cur -> data);
        cur = cur -> right;
      }
    }
  }
  return inorder;
}


};
