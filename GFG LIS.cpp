class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
     int LIS(int ind,int prev_ind,int arr[],int n,vector<vector<int>>&dp){
        if(ind==n)return 0;
        if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
        int len=0+LIS(ind+1,prev_ind,arr,n,dp);
        if(prev_ind==-1 || arr[ind]>arr[prev_ind])
        len=max(len,1+LIS(ind+1,ind,arr,n,dp));
        return dp[ind][prev_ind+1]=len;
    }
    // int lengthOfLIS(vector<int>& arr) {
    //     int n=arr.size();
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //     return LIS(0,-1,arr,n,dp);
    // }
    int longestSubsequence(int n, int arr[])
    {
       // your code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return LIS(0,-1,arr,n,dp);
    }
};
