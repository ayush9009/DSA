class Solution {
public:
    int dir[4]={0,0,1,-1};
    int dic[4]={1,-1,0,0};
    bool Cycle(int i,int j,vector<vector<int>>&vis,int parx,int pary,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
         queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push({{i,j},{-1,-1}});
        char ch=grid[i][j];
        vis[i][j]=1;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int px=q.front().second.first;
            int py=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int rr=row+dir[i];
                int rc=col+dic[i];
                if(rr>=0 && rr<n && rc>=0 && rc<m && grid[rr][rc]==ch){
                    if(!vis[rr][rc]){
                        q.push({{rr,rc},{row,col}});
                        vis[rr][rc]=1;
                    }
                    else if(px!=rr && py!=rc) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                     if(Cycle(i,j,visited,-1,-1,grid))return true;
                }
            }
        }
        return false;
    }
};
