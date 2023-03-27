class Solution {
public:
    //OPTIMISIED SOLUTION
    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0 && j==0)return dp[i][j];
        if(i<0 || j<0)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=min(grid[i][j]+helper(i-1,j,grid,dp),grid[i][j]+helper(i,j-1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // for(int i=1;i<n;i++){
        //     for(int j=1;j<m;j++ ){
        //         sum+=min(grid[i-1][j],grid[])
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(i==0&&j==0)continue;
        //         else if(i==0)
        //             grid[i][j]+=grid[i][j-1];    //agr i==0 hai to bottom mai to ni ja sakte right mai jange
        //         else if(j==0)
        //             grid[i][j]+=grid[i-1][j];  //agr j==0 hai to rigth mai ni ja sakte bottom mai hi ja paogey
        //         else grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);  //iski bat kare yani jaha abhi 5 hai vaha to 
        //         //grid[i-1][j]=4,grid[i][j-1]2 minimum kon 2 to path ho grid=5+2=7,agli bar jaha 1 hai uske liye 5 hi minimum ya 7 ,5 to isliye 5+1=6;
        //         //ab jaha 2 hai min(7,6) i.e 6 therfre 2+6=8 now gridn-1]m-1] 8 minimum hai ya 6 i.e 6 thedre 6+1=7ansere.
        //     }
        // }
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         if(i==0&&j==0)continue;
        //         else if(i==0)grid[i][j]+=grid[i][j-1];
        //         else if(j==0)grid[i][j]+=grid[i-1][j];
        //         else grid[i][j]+=min(grid[i][j-1],grid[i-1][j]);
        //     }
        // }

        //OPTIMISIED SOLUTION IN TERMS OF SPACE
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return helper(n-1,m-1,grid,dp);
         vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)dp[i][j]=grid[i][j];
            else{
                int u=1e9,l=1e9;
                if(i>0)u=dp[i-1][j];
                if(j>0)l=dp[i][j-1];
                dp[i][j]+=grid[i][j];
                dp[i][j]+=min(u,l);
            }
        }
    }
    return dp[n-1][m-1];
        
        
    }
};
