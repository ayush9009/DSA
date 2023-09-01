void printCorner(Node *root)
{

// Your code goes here
  queue<Node*>q;
  q.push(root);
  vector<int>result;
  vector<vector<int>>ans;
  while(q.empty()==false){
      int n=q.size();
      for(int i=0;i<n;i++){
          Node* cur=q.front();
          q.pop();
          result.push_back(cur->data);
          if(cur->left!=NULL)q.push(cur->left);
          if(cur->right!=NULL)q.push(cur->right);
      }
      ans.push_back(result);
      result.clear();
  }
  for(auto it:ans){
      vector<int>result=it;
      if(result.size()>1)cout<<it[0]<<" "<<it[it.size()-1]<<" ";
      else cout<<it[0]<<" ";
    //   cout<<endl;
  }

}
