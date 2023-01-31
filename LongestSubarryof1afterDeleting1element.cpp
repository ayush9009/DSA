class Solution {
public:
//    BAHTREEN QUESTION FOR UNDERSTANDING SLIDING WINDOW CONCEPT
// BRUTE FORCE TIMECOMPLEXITY=O(N^2) SLIDING WINDOW TIMECOMPLEXITY=(O(NLOGN)) 
// apporach keep the window until number of zeros is lesser than or eqaul to 1 when it becomes 2 then reomve all the elements
// from the window till 1st zero
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int cnt_sum=0; //no. of ones
        int cnt_zero=0;
        int i=0;  //starting point for the window
        int n=nums.size();
        for(int j=0;j<n;j++){
            if(nums[j]==1){
                cnt_sum++;
            }else{
                cnt_zero++;
            }
            while(cnt_zero>1){
                cnt_sum=cnt_sum-nums[i];
                if(nums[i]==0)cnt_zero--;
                i++;  //window ab agey badh gi 
            }
            ans=max(ans,cnt_sum);
        }
        if(ans==n)return ans-1;
        return ans;
    }
};
