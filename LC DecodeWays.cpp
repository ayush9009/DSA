class Solution {
public:
    int solve(string s,int i,vector<int>&dp){
        if(i==s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        if(s[i]=='0')return dp[i]=0;
        
        if(i<s.size()-1 && (s[i]=='1' || (s[i]=='2'&&s[i+1]<='6')))
            return dp[i]=solve(s,i+1,dp)+solve(s,i+2,dp);
        return dp[i]=solve(s,i+1,dp);
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return solve(s,0,dp);
    }
};
