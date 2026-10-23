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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 1;
        while (!q.empty()) {
            int sze = q.size();
            vector<int> res;
            
            while (sze--) {
                TreeNode* u = q.front();
                if(u!=NULL)res.push_back(u->val);
                q.pop();
                if (u!=NULL && u->left!=NULL)
                    q.push(u->left);
                if (u!=NULL && u->right!=NULL)
                    q.push(u->right);
            }
            if (flag) {
                ans.push_back(res);
                flag = 0;
            } else {
                reverse(res.begin(), res.end());
                ans.push_back(res);
                flag = 1;
            }
        }

        return ans;
    }
};