class Solution {
public:
    // int LIS(vector<int>&arr,int n){   //DP SOLUTION USING TABULATION METHOD
    //     int lis[n];
    //     lis[0]=1;
    //     for(int i=1;i<n;i++){
    //         lis[i]=1;
    //         for(int j=0;j<i;j++){
    //             if(arr[j]<arr[i])
    //                 lis[i]=max(lis[i],lis[j]+1);
    //         }
    //     }
    //     int res=lis[0];
    //     for(int i=0;i<n;i++){
    //         res=max(res,lis[i]);
    //     }
    //     return res;
    // }
    // int LIS(vector<int>&nums,int n){
    //     int dp[n];
    //     dp[0]=1;
    //     for(int i=1;i<n;i++){
    //         dp[i]=1;
    //         for(int j=0;j<i;j++){
    //             if(nums[j]<nums[i]){
    //                 dp[i]=max(dp[i],dp[j]+1);
    //                 //+1 kuki ye agr max huha to ye include hoja
    //             }
    //         }
    //     }
    //     int res=dp[0];
    //     for(int i=0;i<n;i++){
    //         res=max(res,dp[i]);
    //     }
    //     return res;
    // }
    //OPTIMISED SOLUTION
   // ind values lies frmo 0 n and prev_ind lies from -1 to n-1 ,isliye -1 ko 0  i.e -1 0 1 2 3 aise hojaga for prev_ind
    int LIS(int ind,int prev_ind,vector<int>&arr,int n,vector<vector<int>>&dp){
        if(ind==n)return 0;
        if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
        int len=0+LIS(ind+1,prev_ind,arr,n,dp);
        if(prev_ind==-1 || arr[ind]>arr[prev_ind])
        len=max(len,1+LIS(ind+1,ind,arr,n,dp));
        return dp[ind][prev_ind+1]=len;
    }
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return LIS(0,-1,arr,n,dp);
    }
    //MAXIMUM SUM INCREASING SUBSEQUENCE
    // int dp[n];
    // for(int i=0;i<n;i++){
    //     dp[i]=nums[i];
    // }
    // for(int i=1;i<n;i++){
    //     for(int j=0;j<i;j++){
    //         if(nums[i]>nums[j] && dp[i]<dp[j]+nums[i]){
    //             dp[i]=dp[j]+nums[i];
    //         }
    //     }
    // }
    // int mx=0;
    // for(auto it:dp){
    //     mx=max(it,mx);
    // }
    // return mx;
};
