class Solution {
public:
    // Easiest Dp Solution
    // Note:solution iska vohi hai jo tum soch rai,bas use dp ki form mai kar diya
    // agr smj ni ara solution to no problem ,you can make dp table,and then dry run,after running the table u understand this is the same logic that u think but only difference is that here we do with dp
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(s3.size()!=n+m)return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else if(i==0){
                    dp[i][j]=dp[i][j-1] && s2[j-1]==s3[i+j-1];
                }
                else if(j==0){
                    dp[i][j]=dp[i-1][j] && s1[i-1]==s3[i+j-1];
                }
                else{
                    dp[i][j]=dp[i][j-1] && s2[j-1]==s3[i+j-1] || dp[i-1][j] && s1[i-1]==s3[i+j-1];
                }
            }
        }
        return dp[n][m];
    }
};
