class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>&nums,int n,int i,int j){
        if(j<0||j>=n)return INT_MAX;
        if(i==(n-1))
            return nums[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int s=solve(nums,n,i+1,j);
        int l=solve(nums,n,i+1,j-1);
        int r=solve(nums,n,i+1,j+1);
        return dp[i][j]=min(s,min(l,r))+nums[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int x=solve(nums,n,0,i);
            ans=min(ans,x);
        }
        return ans;
    }
};
