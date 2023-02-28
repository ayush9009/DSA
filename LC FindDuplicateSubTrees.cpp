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
    string helper(TreeNode *root,unordered_map<string,int>&mp,vector<TreeNode*>&ans){
        if(root==NULL)return "";
        string temp=to_string(root->val)+'|'+helper(root->left,mp,ans)+'|'+helper(root->right,mp,ans);
        // cout<<temp<<endl;
        mp[temp]++;
        if(mp[temp]==2){
            ans.push_back(root);
            cout<<root->val<<" ";
        }
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      unordered_map<string,int>mp;
      vector<TreeNode*>ans;
      helper(root,mp,ans);
      return ans;
    }
};
