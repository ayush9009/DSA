class Solution {
public:
    bool dfsBipart(vector<vector<int>>& graph,int s,vector<int>&color){
        queue<int>q;
        color[s]=1;
        q.push(s);
        while(q.empty()==false){
            int u=q.front();
            q.pop();
            for(auto v:graph[u]){
                if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }
                else if(color[u]==color[v]) return false;
            }
        }
        return true;
    }
    // bool dfsBipart(vector<vector<int>>& graph,int n,int src){
    //     vector<int>color(n,-1);
    //     color[src]=1;
    //     queue<int>q;
    //     q.push(src);
    //     while(!q.empty()){
    //         int u=q.front();
    //         q.pop();
    //         for(auto v:graph[u]){
    //             if(color[v]==-1){
    //                 color[v]=1-color[u];
    //                 q.push(v);
    //             }else if(color[v]==color[u])return false;
    //         }
    //     }
    //     return true;
    // }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(dfsBipart(graph,i,color)==false)
                    return false;
            }
        }
       
        return true;
    }
};
