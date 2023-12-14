class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> row(n), col(m);
        int rs=0;
        for(int i=0; i<n; i++){
            rs = 0;
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1)
                    rs++;
            }
            row[i] = rs;
        }
        
        for(int i=0; i<m; i++){
            rs = 0;
            for(int j=0; j<n; j++){
                if(grid[j][i] == 1)
                    rs++;
            }
            col[i] = rs;
        }
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++){
                dp[i][j] = 2*row[i] - n + 2*col[j] - m;
            }
        }
        return dp;
    }
};
