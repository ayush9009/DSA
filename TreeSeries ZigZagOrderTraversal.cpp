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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // vector<vector<int>>ans;
        // if(root==NULL)
        // {
        //     return ans;
        // }
        // queue<TreeNode*>q;
        // q.push(root);
        // int l=0;
        // while(q.empty()==false)
        // {
        //     int count=q.size();
        //     vector<int>result;
        //     for(int i=0;i<count;i++)
        //     {
        //         TreeNode* curr=q.front();
        //         q.pop();
        //         result.push_back(curr->val);
        //         if(curr->left!=NULL)
        //             q.push(curr->left);
        //         if(curr->right!=NULL)
        //             q.push(curr->right);
        //     }
        //     if(l%2!=0)
        //     {
        //            reverse(result.begin(),result.end());
        //            ans.push_back(result);
        //     }
        //     else
        //           ans.push_back(result);   
        //     l++;
        // }
        // return ans;
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(q.empty()==false){
            int n=q.size();
            vector<int>result;
            for(int i=0;i<n;i++){
                TreeNode * cur=q.front();
                q.pop();
                result.push_back(cur->val);
                if(cur->left!=NULL)q.push(cur->left);
                if(cur->right!=NULL)q.push(cur->right);
            }
            if(level%2!=0){
                reverse(result.begin(),result.end());
                ans.push_back(result);
            }
            else{
                ans.push_back(result);
            }
            level++;
        }
        return ans;
    }
};
