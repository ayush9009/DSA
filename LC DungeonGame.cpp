class Solution {
public:
// note:in question it is mention knight can reach specific cell if it has postive health,so if dungeon[i][j]>=0 min health required by knight=1
// but if dungeon[i][j]<=0 then minHealthRqreuired =abs(dungeon[i][j])+1
    int dfs(vector<vector<int>>& dungeon,int row,int col,int sum, vector<vector<int>>&dp){
        int n=dungeon.size();
        int m=dungeon[0].size();
        if(row>=n || col>=m)return 5e5;
        if(row==n-1 && col==m-1){
            if(dungeon[row][col]<=0)return abs(dungeon[row][col])+1;
            else return 1;
        }
        if(dp[row][col]!=-1)return dp[row][col];
        
        int x=dfs(dungeon,row+1,col,sum,dp);
        int y=dfs(dungeon,row,col+1,sum,dp);

        // suppose x,y is postive and now we substract dungeon[row][col]
        // if dungeon[row][col] is +ve :subtracting a positive value from the min(x,y) value will reduce the minimum initial health required for the knight to enter the cell. This is because the knight is gaining health by entering the cell, so the minimum required health decreases.
        //  if dungeon[row][col] is -ve: subtracting a negative value (which is equivalent to adding its absolute value) from the min(health_needed_right, health_needed_down) value will increase the minimum initial health required for the knight to enter the cell. This is because the knight is losing health, so the minimum required health needs to be higher to ensure the knight survives.

        int minHealthRequired=min(x,y)-dungeon[row][col]; 
        
        // dp[row][col]: signifes min health rerqeuire to reach particular cell
        // now suppose if minHealthRequired<=0 then 
        // dp[row][col]=1 means kam se kam itni health to ho tabhi is partuclar cell par aap poach payenge
        return dp[row][col]=(minHealthRequired<=0) ? 1:minHealthRequired;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       
        int x= dfs(dungeon,0,0,0,dp);
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return x;
         
    }
};
