class Solution {
public:
    long long ans=0;
    int dfs(vector<vector<int>>&adj,int node,vector<int>&vis,int seats){
        vis[node]=1;
        long long cnt=1;
        for(int i=0;i<adj[node].size();i++)   //ek bnde ki sath kon kon jara 
        {
            int cur=adj[node][i];
            if(!vis[cur])cnt+=(dfs(adj,cur,vis,seats));
        }
                               
                               long long x=cnt/seats;
                               if(cnt%seats)x++;   //mtlb aur gadi lagegi 
                               if(node!=0)ans+=x;
                               
                               return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        //ek city se dusre city mai jane kai kitna fuel lagega jitni gaadi hongi
        if(roads.size()==0)return 0;
        ans=0;
        int n=roads.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n;i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<int>vis(n+1,0);
        dfs(adj,0,vis,seats);
        return ans;
    }
};
