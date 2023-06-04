class Solution {
public:
    // void dfs(int s,int n,vector<vector<int>>&isConnected,vector<bool>&visited){
    //     visited[s]=true;
    //     vector<int>adj;
    //     for(int i=0;i<n;i++)
    //     {
    //         int x=isConnected[s][i];
    //         if(x==1)
    //             adj.push_back(i);
    //     }
    //     for(auto x:adj)
    //     {
    //         if(!visited[x])
    //         {
    //             dfs(x,n,isConnected,visited);
    //         }
    //     }
    // }
    void dfs(vector<vector<int>>&ad,vector<bool>&visited,int s,int n)
    {
       visited[s]=true;
        vector<int>adj;
        for(int i=0;i<n;i++)
        {
            int x=ad[s][i];  //x=adj[0][1]
            if(x==1)adj.push_back(i);
        }
        for(auto x:adj){
            if(visited[x]==false)
            {
                dfs(ad,visited,x,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        // int n=isConnected.size();
        // vector<bool>visited(n,false);
        // int count=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(!visited[i])
        //     {
        //         count++;
        //         dfs(i,n,isConnected,visited);
        //     }
        // }
        // return count;
        int count=0;
        int n=adj.size();
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false)
            {
                dfs(adj,visited,i,n);
                count++;
            }
        }
        return count;
    }
};
