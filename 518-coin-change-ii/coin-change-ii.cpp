class Solution {
public:
    int change(int amount, vector<int>& coins) {
       int n=coins.size();
    //    return helper(0,coins,amount);
       vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(amount+1,0));
       for(int i=0;i<=n;i++){
        dp[i][0]=1 ; //0 coins ,leke
       }

       for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            if(coins[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
       }

       return dp[n][amount];
    }
};