class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        // since left rotated sorted,(to two parts honge bht sorted, )
        // deko alg alg case bn sake , kuki ni pata ki kaha se vo rotate
        //  like 135.    ->513 ye decrasing order sort
        //  01234567 , -> 4567012 ye increasing order sort se shuru hora
        while (low <= high) {
            int mid = (low + (high - low) / 2);
            if (nums[mid] == target)
                return mid;
            else if (nums[low] <= nums[mid]) {
                // means incresaing mai sorted hai,
                if (nums[low] <= target && nums[mid] > target) {
                    // pta chle left half mai jana chaiye, ya kaha
                    high = mid-1;
                } else low = mid +1;
            } else {
                if (nums[mid] <target && target <= nums[high]) {
                    low = mid+1;
                } else {
                   high = mid - 1;
                }
            } 
        }
        return -1;
    }
};