class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        vector<vector<int>> v(m,vector<int>(n,0));
        queue<vector<int>> q;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]) q.push({i,j,0});
            }
        }
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        while (q.size()) {
            int r=q.front()[0],c=q.front()[1],d=q.front()[2];
            if (ans<d) ans=d;
            for (int i=0;i<4;i++) {
                int nr=r+dr[i],nc=c+dc[i];
                if (nr>=0&&nc>=0&&nr!=m&&nc!=n&&grid[nr][nc]==0&&v[nr][nc]==0) {
                    v[nr][nc]=1;
                    q.push({nr,nc,d+1});
                }
            }
            q.pop();
        }
        if (ans) return ans;
        return -1;
    }
};
