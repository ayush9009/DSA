class Solution {
public:
// Observe and apply dijkstra's algo
    int minimumObstacles(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        q.push({0,0});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>obstacleRemoved(n,vector<int>(m,INT_MAX));
        obstacleRemoved[0][0]=0;
        while(q.empty()==false){
            int size=q.size();
          for(int t=0;t<size;t++){
           int x=q.front().first;
           int y=q.front().second;
           q.pop();
           int dx[]={0,-1,0,1};
           int dy[]={-1,0,1,0};
            for(int i=0;i<4;i++){
                    int nx=dx[i]+x;
                    int ny=dy[i]+y;
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&obstacleRemoved[x][y]+grid[nx][ny]<obstacleRemoved[nx][ny]){
                       obstacleRemoved[nx][ny]=obstacleRemoved[x][y]+grid[nx][ny];
                       q.push({nx,ny});
                    }
            }
          }
        }
        return obstacleRemoved[n-1][m-1];
    }
};
