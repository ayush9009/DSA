class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(n-i>=nums[i]){
                ans=nums[i];
            }else{
                ans=max(ans,n-i);
            }
        }
        return ans;
    }
};
