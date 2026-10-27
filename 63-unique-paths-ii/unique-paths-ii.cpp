class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 ||
            grid[i][j] == 1)
            return 0;
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return 1;

        int right = helper(i, j + 1, grid);
        int down = helper(i + 1, j, grid);

        return (down + right);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (grid[i][0] != 1)
                dp[i][0] = 1;
            else
                break; // kuki agey to ja ni sakta obstracle h
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] != 1)
                dp[0][j] = 1;
            else
                break; // kuki agey to ja ni sakta obstracle h
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int right = 0, bottom = 0;
                if (grid[i][j] != 1) {
                    if (j - 1 >= 0) {
                        right = dp[i][j - 1];
                    }
                    if (i - 1 >= 0) {
                        bottom = dp[i - 1][j];
                    }
                    dp[i][j] = right + bottom;
                }
            }
        }
        return dp[n - 1][m - 1];
        // return helper(0,0,grid);
    }
};