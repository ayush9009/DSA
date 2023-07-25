class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int helper(int n,vector<int>&dp){
        if(n<=1)return dp[n]=1;
        
        if(dp[n]!=-1)return dp[n];
        
        dp[n]=helper(n-1,dp)+helper(n-2,dp);
        return dp[n];
    }
    int countWays(int n)
    {
        // your code here
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};
