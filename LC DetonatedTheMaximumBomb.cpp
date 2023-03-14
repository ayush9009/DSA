class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<int>&visited,int &src,int &cnt){
        visited[src]=true;
        cnt++;
        for(int j=0;j<adj[src].size();j++){
            if(!visited[adj[src][j]]){
                dfs(adj,visited,adj[src][j],cnt);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<bombs.size();i++){
            //directed graph bna diya ab jo root(i)node se conntected unhe i node detonatekrsake sirf 
            long long int x1=bombs[i][0];
            long long int y1=bombs[i][1];
            long long int r1=bombs[i][2];
            for(int j=0;j<n;j++){
                if(i!=j){
                    long long int x2=abs(x1-bombs[j][0]);
                    long long int y2=abs(y1-bombs[j][1]);
                    if((x2*x2) + (y2*y2) <= r1*r1)  //ye exmples dekr pata chla
                    adj[i].push_back(j);
                }
            }
        }
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            // if(!visited[i]){
                int cnt=0;
                 vector<int>visited(n,0);
                dfs(adj,visited,i,cnt);
                res=max(res,cnt);
            // }
        }
        return res;
        // int k,l;
        // int mx=INT_MIN;
        // int m=bombs.size();
        // int n=bombs[0].size();
        // for(int i=0;i<m;i++){
        //         if(mx<bombs[i][n-1]){
        //             mx=bombs[i][n-1];
        //             k=i;
        //         }      
        // }
        // int count=1;
        // for(int i=0;i<m;i++){
        //         if(i!=k){
        //             if(bombs[i][n-1]<=bombs[k][n-1])
        //                 count++;
        //         }
        // }
        // return count;
    }
};
