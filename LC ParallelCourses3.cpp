//here we use the concept of topological sort to complete n courses
// where dist[u] is the number of months require to compleete the course,dis[u] is calculated by
// maximum distance +times[u]
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>graph(n,vector<int>());
        vector<int>indegree(n);
        for(auto &edge:relations){
            int prev=edge[0]-1;
            int next=edge[1]-1; //-1 kuki question mai kahani 1 2 3 aise shuru haiaurhum0sekrenge
            graph[prev].push_back(next);
            indegree[next]++;
        }
        queue<int>q;
        vector<int>dist(n,0);
        for(int u=0;u<n;u++){
            if(indegree[u]==0){
                q.push(u);
                dist[u]=time[u];
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:graph[u]){
                // updatte dist[v] maximum distance of predecessor(that appear just before) nodes
                //if we get he dis[u] of predecrsor nodes then we get for currnt node also
                //because to next course u have to complete prev course
                // thatwhy we use concept of topo sort to complete n courses
                dist[v]=max(dist[v],dist[u]+time[v]); 
                if(--indegree[v]==0)q.push(v);
            }
        }
        return *max_element(dist.begin(),dist.end());

    }
};
