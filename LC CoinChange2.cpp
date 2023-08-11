class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<amount+1;j++){
                if(j==0)dp[i][j]=1;//agr sum=0,aur array=1,2,3,4, and so on to kya possible hai ha empty subset islieu 1.agr sum=0 aur aur array elements bhi zero hi hai matlb ek bhi element ni hai to i.edp[0][0]=1
                if(i==0)dp[i][j]=0;//agr sum=1,2,3,4, aur array elements aapke paas hai ni to 0
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j)
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][amount];
    }
};
