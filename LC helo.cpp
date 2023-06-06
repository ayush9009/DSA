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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false)
        {
            vector<int>result;
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                result.push_back(curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans.push_back(result);
        }
        reverse(ans.begin(),ans.end());
        return ans;
         vector<vector<int>> ans;
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(!q.empty())
        {
            TreeNode *cur=q.front();
            q.pop();
            if(cur==NULL)
            {
                ans.push_back(v);
                if(q.empty())
                return ans;
                else
                {
                    q.push(NULL);
                    v.clear();
                    continue;
                }
            }
            v.push_back(cur->val);
            if(cur->left)
            q.push(cur->left);
            if(cur->right)
            q.push(cur->right);
        }
        // reverse(ans.begin(),ans.end());
        return ans;

    }
};
