class Solution {
  public:
    int ed(int n,int m,string &s,string &t){
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int j=0;j<=m;j++)dp[0][j]=j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
        return dp[n][m];
    }
    int editDistance(string s, string t) {
        // Code here
        int m=s.size();
        int n=t.size();
        return ed(m,n,s,t);
    }
};
