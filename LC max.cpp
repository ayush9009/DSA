class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        double sum=0;
        ans = sum = nums[0];
        for(int i=1; i<n; i++){
            sum += nums[i];
            int x = ceil(sum/(i+1));
            ans =  max(ans, x);
        }   
        return ans;
    }
};
