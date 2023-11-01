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
// class Solution {
// public:
//     void traverse(TreeNode *root,unordered_map<int,int>&m){
//         if(root==NULL)return ;
//         m[root->val]++;
//         traverse(root->right,m);
//         traverse(root->left,m);
//     }
//     vector<int> findMode(TreeNode* root) {
//         unordered_map<int,int>m;
//         traverse(root,m);
//         priority_queue<pair<int,int>>pq;
//         unordered_map<int,int>:: iterator it=m.begin();
//         while(it!=m.end()){
//             pq.push({it->second,it->first});
//             it++;
//         }
//         vector<int>result;
//         result.push_back(pq.top().second);
//         int temp=pq.top().first;
//         pq.pop();
//         while(!pq.empty()){
//             if(pq.top().first<temp)break;
//             result.push_back(pq.top().second);
//         }
//         return result;
//     }
// };
class Solution {
public:
    void helper(TreeNode *root,unordered_map<int,int> &m){
        if(root==NULL) return;
        m[root->val]++;
        helper(root->right,m);
        helper(root->left,m);
    }
    void inorder(vector<int>&result,TreeNode* root){
        if(root!=NULL){
            result.push_back(root->val);
            inorder(result,root->left);
            inorder(result,root->right);
        }

    }
    vector<int> findMode(TreeNode* root) {
        // unordered_map<int,int> m;
        // helper(root,m);
        // priority_queue<pair<int,int>> pq;
        // unordered_map<int,int>:: iterator itr=m.begin();
        // while(itr!=m.end()){
        //     pq.push({itr->second,itr->first});
        //     itr++;
        // }
        // vector<int> ans;
        // ans.push_back(pq.top().second);
        // int temp=pq.top().first;
        // pq.pop();
        // while(!pq.empty()){
        //     if(pq.top().first<temp) break;
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return ans;
        // mode: most occursing element
        vector<int>result;
        inorder(result,root);
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        for(auto it:result){
            mp[it]++;
            maxi=max(maxi,mp[it]);
        }
        vector<int>ans;
        for(auto it:mp){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
