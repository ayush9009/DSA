class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int left=0,right=0;
        int cnt=0;
        int maxLen=0;
        for(right;right<nums.size();right++){
            if(nums[right]==0)cnt++;
            
            while(cnt>k){
                if(nums[left]==0){
                    cnt--;
                }
                left++;
            }
            
            maxLen=max(maxLen,right-left+1);
            
        }
        return maxLen;
    }
};
