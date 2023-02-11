class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<int> graph[n+1];
        for (vector<int> &red : redEdges)       graph[red[0]+1].emplace_back(red[1]+1);
        for (vector<int> &blue : blueEdges)     graph[blue[0]+1].emplace_back(-blue[1]-1);
        
        vector<int> distances(n, -1);
        distances[0] = 0;
        
        vector<bool> posVis(n+1, false), negVis(n+1, false);
        posVis[1] = negVis[1] = true;
        
        queue<int> q;
        for (int nex : graph[1])
        {
            int absnex = abs(nex);
            bool neg = nex < 0;
            if ((neg && negVis[absnex]) || (!neg && posVis[absnex]))
                continue;
            
            q.emplace(nex);
            if (neg)    negVis[absnex] = true;
            else        posVis[absnex] = true;
        }
        
        int dist = 0;
        while (!q.empty())
        {
            dist++;
            int sz = q.size();
            for (int s = 0; s < sz; s++)
            {
                int node = q.front();
                q.pop();
                
                int absnode = abs(node);
                bool nodeneg = node < 0;
                
                if (distances[absnode -1] == -1)
                    distances[absnode - 1] =  dist;
                
                for (int adj : graph[absnode])
                {
                    int absadj = abs(adj);
                    bool adjneg = adj < 0;
                    
                    if ((nodeneg && adjneg) || (!nodeneg && !adjneg))
                        continue;
                    else if ((adjneg && negVis[absadj]) || (!adjneg && posVis[absadj]))
                        continue;
                    
                    q.emplace(adj);
                    if (adjneg) negVis[absadj] = true;
                    else        posVis[absadj] = true;
                }
            }
        }
        
        return distances;
    }
};
