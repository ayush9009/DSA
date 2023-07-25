int helper(vector<int>&prices,vector<vector<vector<int>>>dp,int n){
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){  //two values possbible either u buy or u sell
            for(int cap=1;cap<=2;cap++){
                if(buy){
                    dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                }else{
                    //sell
                    dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}
int maxProfit(vector<int>&prices){
    // dp[ind][buy][cap]
    // cap maximum values:0,1,2
    // buy means 2 values ,either u buy or u sell
    // if buy means -prices[i]+dp[ind+1][0][cap] 0 means ab aap sell kar sako na ki buy and same for sell
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    
    return helper(prices,dp,n);
}
