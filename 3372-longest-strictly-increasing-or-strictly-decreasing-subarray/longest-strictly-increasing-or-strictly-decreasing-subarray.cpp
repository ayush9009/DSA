class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // int maxi1 = 1, maxi2 = 1;
        // int i = 0, n = nums.size();

        // for (int j = 1; j < n; j++) {
        //     if (nums[j] > nums[j - 1]) {
        //         maxi1 = max(maxi1, j - i + 1);
        //     } else {
        //         i = j;
        //     }
        // }

        // i = 0;
        // for (int j = 1; j < n; j++) {
        //     if (nums[j] < nums[j - 1]) {
        //         maxi2 = max(maxi2, j - i + 1);
        //     } else {
        //         i = j;
        //     }
        // }

        // return max(maxi1, maxi2);
        int n=nums.size();
        int maxi1=1,maxi2=1,inc=1,dec=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
                dec=1;
            }else if(nums[i]<nums[i-1]){
                dec++;
                inc=1;
            }else{
                inc=dec=1;
            }
            maxi1=max(maxi1,inc);
            maxi2=max(maxi2,dec);
        }
        return max(maxi1,maxi2);
    }
};
