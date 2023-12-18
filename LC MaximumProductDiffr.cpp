class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int prod=1;
        int a,b,c,d;
        a=nums[0];
        b=nums[1];
        c=nums[n-2];
        d=nums[n-1];
        prod=c*d-a*b;
        return prod;
    }
};
