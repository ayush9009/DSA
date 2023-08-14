class Solution {
  public:
    void dfs(int node,vector<vector<int>>&adj, vector<int>&vis){
        vis[node]=1;
        for(int i=0;i<adj.size();i++){
            if(adj[node][i]==1){
                if(!vis[i])dfs(i,adj,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int cnt=0;
        vector<int>vis(V,0);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};
