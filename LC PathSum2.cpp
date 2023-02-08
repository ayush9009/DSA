class Solution {
public:
    int minJumps(vector<int>&nums,int n){
       //  if(n==1) return 0;
       //  int res=INT_MAX;
       //  for(int i=0;i<=n-2;i++){
       //      if(i+nums[i]>=n-1){
       //          int sub_res=minJumps(nums,i+1);
       //          if(sub_res!=INT_MAX)
       //              res=min(res,sub_res+1);
       //      }
       //  }
       // return res;
    int dp[n];
        dp[0]=0;
        for(int i=1;i<n;i++)
            dp[i]=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]+j>=i){
                    if(dp[j]!=INT_MAX)
                        dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        return minJumps(nums,n);
    }
};
