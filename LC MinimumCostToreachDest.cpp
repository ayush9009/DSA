
#define pr pair<int, pair<int, int>>
#define ll long long int

class Solution {
public:

    
    int minCost(int maxTime, vector<vector<int>>& ed, vector<int>& pass) {
        int n = pass.size();
        vector<pair<int, int>> adj[n];
        
        //making a graph
        for(vector<int> e: ed) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        //taking min priority queue as {cost, vertex, time} 
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        pq.push({pass[0], {0, 0}});

        unordered_map<int, int> vis;//vertex,time
        while(!pq.empty()) {
            pr crr = pq.top(); pq.pop();
            int curr = crr.second.first, time = crr.second.second, cost = crr.first;
            
            if(curr == n-1) return cost;
            vis[curr] = time;
            
            for(pair<int, int> p: adj[curr]) {
                int ad = p.first, ctime = p.second;
                int ttime = time + ctime;
                // if the node is already visited,and
// If we encounter a vertex cr again, and we have already reached it with a smaller or equal totalTime, then there is no need to reprocess it because we have already found a better or equally good path to reach cr. 
                if(vis.find(ad) != vis.end() && vis[ad] <= ttime) continue;
                vis[ad] = ttime;
                
                if(ttime <= maxTime) pq.push({cost + pass[ad], {ad, ttime}});
            }
            
        }
        return -1;

    }
};
