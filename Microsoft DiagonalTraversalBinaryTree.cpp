void helper(Node* root,int diagonal,unordered_map<int,vector<int>>&mp){
    if(root==NULL)return ;
    
    mp[diagonal].push_back(root->data);
    helper(root->left,diagonal+1,mp);
    helper(root->right,diagonal,mp);
}
vector<int> diagonal(Node *root)
{
   // your code here
   unordered_map<int,vector<int>>mp;
   helper(root,0,mp);
   vector<int>result;
   for(int i=0;i<mp.size();i++){
       vector<int>ans=mp[i];
       for(int i=0;i<ans.size();i++){
           result.push_back(ans[i]);
       }
   }
   return result;
}
