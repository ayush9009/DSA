
class Solution {
public:
 bool isValid(int i,int j,int row,int col)
{
    if(i<0||j<0||i>row||j>col)
        return false;
    return true;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        // int n = mat.size();
        // int m = mat[0].size();

        // vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        // queue<pair<int, int>> q;

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (mat[i][j] == 0) {
        //             dist[i][j] = 0;
        //             q.push({i, j});
        //         }
        //     }
        // }

        // vector<vector<int>> vis(n, vector<int>(m, 0));

        // int dx[] = {-1, 0, 1, 0};
        // int dy[] = {0, 1, 0, -1};

        // while (!q.empty()) {

        //     auto it = q.front();
        //     q.pop();

        //     int u = it.first;
        //     int v = it.second;

        //     if (vis[u][v] == 1)
        //         continue;

        //     vis[u][v] = 1;

        //     for (int i = 0; i < 4; i++) {

        //         int adjX = u + dx[i];
        //         int adjY = v + dy[i];

        //         if (adjX >= n || adjY >= m || adjX < 0 || adjY < 0)
        //             continue;

        //         if (mat[u][v] == 0) {

        //             if (mat[adjX][adjY] == 0)
        //                 continue;

        //             if (dist[u][v] != INT_MAX &&
        //                 dist[u][v] + 1 < dist[adjX][adjY]) {

        //                 dist[adjX][adjY] = dist[u][v] + 1;
        //                 q.push({adjX, adjY});
        //             }

        //         } else {

        //             if (dist[adjX][adjY] != INT_MAX &&
        //                 dist[adjX][adjY] + 1 < dist[u][v]) {

        //                 dist[u][v] = dist[adjX][adjY] + 1;
        //             }

        //             if (vis[adjX][adjY] != 1)
        //                 q.push({adjX, adjY});
        //         }
        //     }
        // }

        // return dist;
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dist(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int row=mat.size()-1;
        int col=mat[0].size()-1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int i=it.first;
            int j=it.second;

            if(isValid(i+1,j,row,col) && dist[i+1][j]==-1){
                q.push({i+1,j});
                dist[i+1][j]=dist[i][j]+1;
            }
            if(isValid(i-1,j,row,col) && dist[i-1][j]==-1){
                q.push({i-1,j});
                dist[i-1][j]=dist[i][j]+1;
            }
            if(isValid(i,j+1,row,col) && dist[i][j+1]==-1){
                q.push({i,j+1});
                dist[i][j+1]=dist[i][j]+1;
            }
            if(isValid(i,j-1,row,col) && dist[i][j-1]==-1){
                q.push({i,j-1});
                dist[i][j-1]=dist[i][j]+1;
            }
        }
        return dist;
    }
};
