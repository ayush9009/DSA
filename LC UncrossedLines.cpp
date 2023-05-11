class Solution {
public:
    int helper(vector<vector<int>>&dp,int i,int j,vector<int>&nums1,vector<int>&nums2){
        if(i>=nums1.size() || j >=nums2.size())return 0; //base cases
        if(dp[i][j]!=-1)return dp[i][j];  //means we get the answer
        int result=0;
        if(nums1[i]==nums2[j]){
            result=1+helper(dp,i+1,j+1,nums1,nums2); //if they matched then we move forward in both nums
        }
        result=max(result,max(helper(dp,i+1,j,nums1,nums2),helper(dp,i,j+1,nums1,nums2)));
        dp[i][j]=result;
        return result;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
       vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
       return helper(dp,0,0,nums1,nums2);
    }
};
