class Solution {
public:
    int helper(int i, vector<int>&nums, int sum){
        if(i>=nums.size())return sum;
        
        int take= helper(i+2,nums,sum+nums[i]);
        int not_take = helper(i+1,nums,sum);
        return max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        dp[0]=nums[0]; 
        if(n==1)return nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int take = nums[i] + dp[i-2];
            int not_take = dp[i-1];

            dp[i]=max(take,not_take);
        }
        return dp[n-1];

        // return helper(0,nums,0);
    }
};