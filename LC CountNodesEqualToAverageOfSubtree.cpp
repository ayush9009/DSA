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
    // int ans=0;
    // pair <int,int>dfs(TreeNode *root){
    //     if(!root)return{0,0};
        
    //     pair<int,int>t1=dfs(root->left);
    //     pair<int,int>t2=dfs(root->right);
    //     int sum=root->val+t1.first+t2.first;
    //     int count=1+t1.second+t2.second;
        
    //     if(root->val==sum/count)
    //         ans+=1;
    //     return {sum,count};
    // }
    int ans=0;
    pair<int,int>dfs(TreeNode* root){
        if(root==NULL)return {0,0};

        pair<int,int>p1=dfs(root->left);
        pair<int,int>p2=dfs(root->right);
        int sum=root->val+p1.first+p2.first;
        int cnt=1+p1.second+p2.second;

        if(root->val ==sum/cnt)ans++;

        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int>t=dfs(root);
        return ans;
    }
};
