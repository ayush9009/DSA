class Solution {
public:
    //THINK AND THINK
    //BECAUSE IT IS EASY QUESTION ON SLIDING WINDOW
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=0;
        long long target=0;
        int l=0;
        int r=0;
        while(r<nums.size()){
            target+=nums[r];
            //r-l+1//window length
            while((long long) nums[r]*(r-l+1) > target+k){
                target-=nums[l];
                l+=1;
            }
            //valid condtion ie. windowlength*nums[j] <= target+k so we include in target and incremnt
            // the window size
            res=max(res,r-l+1);  //jitni maximumwindow lenth vo answer hoga humara
            r+=1;
        }
        return res;
    }
};
