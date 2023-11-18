// class Solution {
// public:
//     //THINK AND THINK
//     //BECAUSE IT IS EASY QUESTION ON SLIDING WINDOW
//     int maxFrequency(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         int res=0;
//         long long target=0;
//         int l=0;
//         int r=0;
//         while(r<nums.size()){
//             target+=nums[r];
//             //r-l+1//window length
//             while((long long) nums[r]*(r-l+1) > target+k){
//                 target-=nums[l];
//                 l+=1;
//             }
//             //valid condtion ie. windowlength*nums[j] <= target+k so we include in target and incremnt
//             // the window size
//             res=max(res,r-l+1);  //jitni maximumwindow lenth vo answer hoga humara
//             r+=1;
//         }
//         return res;
//     }
// };











































class Solution {
public:
    
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long target=0;
        int l=0,r=0;
        int n=nums.size();
        int res=0;
        while(r<n){
            target+=nums[r];
// if (long long)nums[r]*(r-l+1) <= target+k means,we add this new element to window and make other elements eqaul to it else not 
            while((long long)nums[r]*(r-l+1) > target+k){
                target-=nums[l];
                l+=1;
            }
            res=max(res,r-l+1);
            r+=1;
        }
        return res;
    }
};
