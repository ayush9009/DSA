class Solution
{
   public:
   int solve(int ind1, int ind2, string s1, string s2,vector<vector<int>>&dp){
       if(ind1==s1.length()||ind2==s2.length())return 0;
       
       if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
       
       if(s1[ind1]==s2[ind2]){
           return dp[ind1][ind2] = 1+solve(ind1+1,ind2+1,s1,s2,dp);
       }
       
       return dp[ind1][ind2] = max(solve(ind1+1,ind2,s1,s2,dp),solve(ind1,ind2+1,s1,s2,dp));
   } 
   int lcs(int n, int m, string s1, string s2)
   { 
       vector<vector<int>>dp(n,vector<int>(m,-1));
       return solve(0,0,s1,s2,dp);
   }
};
