class Solution{   
public:
    int LongestPalindromicSubsequence(string x,string y){
        int n=x.size();
        int m=y.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
    int countMin(string s){
        // code here 
        string str=s;
        reverse(s.begin(),s.end());
        string m=s;
        int ans=LongestPalindromicSubsequence(str,m);
        return str.size()-ans;
    }
};
