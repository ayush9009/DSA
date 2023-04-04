class Solution {
public:
    double dp[105][105];
    double helper(vector<int>&nums,int cur,int k){
        if(cur>=nums.size() || k<0)return 0; 
        //cuts must be less than size(meansoutof bound ni jana chaiye)
        //  and k should be greater than 0 hona chaiye
        if(k==0)return INT_MIN;  //means i use all the cuts

        if(dp[cur][k]!=0)return dp[cur][k];
        double ans=0;
        double sum=0;
        for(int i=cur;i<nums.size();i++){
            sum+=nums[i]; 
            //sum=sum till the ith point

            ans=max(ans,sum/(i-cur+1)+helper(nums,i+1,k-1));

            //in above line i try to maximise our result,
            // so if i make the cut,then sum/total length of subarrya that u make cut
            // if i make the cut then total cuts reduces by 1 i.e k-1
            // and also i make the cut so,i move forward i.e i+1
        }
        return dp[cur][k]=ans;//here we return the maximum answer
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
      memset(dp,0,sizeof(dp));
      return helper(nums,0,k);
    }
};
