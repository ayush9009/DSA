class Solution {
public:
   
  const long long MOD = 1000000007;
    long long helper(int n,int x,long long i,long long sum ,vector<vector<long long>>&dp){
        if(n==sum)return 1;  //means ek count increment hojagi,kuki ek bar to milgya vo sum
        if(n<sum || i>300)return 0;
        if(dp[i][sum]!=-1)return dp[i][sum];
        return dp[i][sum]=(helper(n,x,i+1,pow(i,x)+sum,dp) + helper(n,x,i+1,sum,dp) + MOD)%MOD;
    }
    int numberOfWays(int n, int x) {
        vector<vector<long long>>dp(301,vector<long long>(301,-1));
        return helper(n, x, 1,0,dp);
    }

};
