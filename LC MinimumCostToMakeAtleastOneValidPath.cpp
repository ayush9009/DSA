class Solution {
public:
    int n , m ;
    bool isValid(int x , int y)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>>dp(102,vector<int>(102,INT_MAX));
        n = grid.size();
        m = grid[0].size();
        vector<pair<int,int>>directions = {{0,1} , {0,-1} , {1,0} , {-1,0}};
        // / memset(dp,100000,sizeof(dp));  //inditally dp mai sab 100000
        dp[0][0] = 0;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            for(int i=0;i<4;i++)
            {
                int X = x + directions[i].first;//jis cordinate pai yani aap abhi ho vo nikala
                int Y = y + directions[i].second;
                if(isValid(X,Y))
                {
                    if(i+1 == grid[x][y] && dp[X][Y] > dp[x][y])
                    {
                        //i+1==grid[x][y] direct dekrai yah
                    // kahe agr upr se neeche ane kai arrow same to aa sako else no to agr dp[0][1] pai 
                    // down arrao hai tabhi to neeche aa sako else not to vohi check kar rai
                        dp[X][Y] = dp[x][y];
                        q.push({X,Y});
                    }
                    else if(dp[x][y] + 1 < dp[X][Y])//+1 yani vo cost hiski bt hori quetion mai{
                    {
                        dp[X][Y] = dp[x][y] + 1;
                        q.push({X,Y});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};
