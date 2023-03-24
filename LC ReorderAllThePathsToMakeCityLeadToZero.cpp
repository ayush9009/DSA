class Solution {
public:
    int dfs(vector<vector<pair<int, int>>> const &graph, int const i, vector<int> &vis) {
        vis[i] = 1;     
        int ans = 0;
        for (auto [n, dir] : graph[i]) {
            if (vis[n] == 0) {
                if (dir == 1) ans++;
                ans += dfs(graph, n, vis);
            }
        }
        return ans;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto conn : connections) {
            graph[conn[0]].push_back({conn[1], 1});
            graph[conn[1]].push_back({conn[0], -1});
        }
        
        vector<int> vis(n, 0);
        return dfs(graph, 0, vis);
    }
};
