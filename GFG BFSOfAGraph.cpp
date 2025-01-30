class Solution {
  public
    // Function to return Breadth First Traversal of given graph.
   
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans,vis(V,0);
       
        queue<int>q;
        q.push(0)
        vis[0]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans.push_back(it);
            for(auto node : adj[it]){
                if(!vis[node]){
                    vis[node]=1;
                    q.push(node);
                }
            }
        }
        return ans;
    }
};
