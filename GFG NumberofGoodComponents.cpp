class Solution {
  public:
    
   void dfs(int node,int &vertices,int &edges,vector<vector<int>>&adj,vector<int>&vis){
       vis[node]=1;
       vertices++;
       edges+=adj[node].size();
       for(auto it:adj[node]){
        //   int x=it[1];/
           if(!vis[it]){
               dfs(it,vertices,edges,adj,vis);
           }
       }
   }

    int findNumberOfGoodComponent(int v, vector<vector<int>>& adj) {
    //   note:if a component is a fully connected component then it must have (n*(n-1)/2)edges.
    int cnt=0;
    vector<int>vis(v+1,0);
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            int vertices=0,edges=0;
            dfs(i,vertices,edges,adj,vis);
            edges/=2;
            if(edges==(vertices*(vertices-1)/2))cnt++;
        }
    }
    return cnt;
    }
};
