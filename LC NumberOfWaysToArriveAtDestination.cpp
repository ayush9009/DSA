class Solution {
public:

    //VVIP QUESTION ON SHORTEST PATH
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
          priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> >pq;
        vector<long long>dist(n,LONG_MAX);
        vector<int>path(n,0);
        dist[0]=0;
        path[0]=1;
        pq.push({0,0});  //distance node   node and its distance
        while(pq.empty()==false){
            pair<long long,int>t=pq.top();
            pq.pop();
            for(auto &it:adj[t.second]){
                long long vert=it.first;
                long long edge=it.second;
                if(dist[vert] > dist[t.second]+edge){
                    dist[vert]=dist[t.second]+edge;   // for node 1 dist[1]=dist[0]+2
                    pq.push({dist[vert],vert});//pq.push({2,1}) //dist node
                    path[vert]=path[t.second]%mod;   //path bhi update kar diya min dist path
                }
                else if(dist[vert]==t.first+edge){   //agr manlo pahle 0-6 dist=7 ,aur ab 0-4-6 dist=7
                // hai to to hum kya kahrai path[6]increment kar do,aur mod bhi kar do 
                    path[vert]+=path[t.second];
                    path[vert]%=mod;
                }
            }

        }
        return path[n-1];
    }
};
