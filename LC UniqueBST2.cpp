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
//  i want the dp solution
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
       if(n==0)return {};
       return dfs(1,n);
    }
    vector<TreeNode*>dfs(int l,int r){
        vector<TreeNode*>result;
        if(l>r)return {NULL};
        
        for(int i=l;i<=r;i++){
            auto left=dfs(l,i-1);
            auto right=dfs(i+1,r);
            for(auto x:left){
                for(auto y:right){
                    TreeNode *root=new TreeNode(i);
                    root->left=x;
                    root->right=y;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
