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
    int parent,child;
    unordered_map<int,bool>vis;         //vis yaha infected person ka kam karege jojo infected unke liye 1 else 0
    unordered_map<int,vector<int>>g;
    int ans=0;
    void buildGraph(TreeNode*root){
        if(!root)return;
        parent=root->val;
        if(root->left) {                //mtlb agr rooot ->left !=NULL to hi ye condition chlegi
        child=root->left->val;
        g[parent].push_back(child);
        g[child].push_back(parent);
        }
        if(root->right){
             child=root->right->val;
             g[parent].push_back(child);
             g[child].push_back(parent);
        }
        buildGraph(root->left);
        buildGraph(root->right);
    }
     void dfs(int s,int depth){
         if(vis[s])return;   //agr vo pahle se infected to return kar do ,kuki use bar bar check karne ki jarorat ni
         vis[s]=true;           //mtlb agr start abhi infected lakin aap uspr paoch gye to true kar diya
         ans=max(ans,depth);
         for(int &v:g[s]){
             dfs(v,depth+1);
         }
         vis[s]=0;
     }
    int amountOfTime(TreeNode* root, int start) {
        buildGraph(root);
        dfs(start,0);
        return ans;
    }
};
