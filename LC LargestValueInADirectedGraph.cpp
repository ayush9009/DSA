class Solution {
public:
//badiya question ,topologicalsort+Dp
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>>graph(n);
        vector<int>indegree(n,0);
        vector<vector<int>>dp(n,vector<int>(26));
        queue<int>q;
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        int ans=0,cycle=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans=max(ans,++dp[u][colors[u]-'a']);
            cycle++;
            for(auto v:graph[u]){
                for(int i=0;i<26;i++){
                    dp[v][i]=max(dp[v][i],dp[u][i]);
                }
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }
        return (cycle<n)?-1:ans;
    }
};
