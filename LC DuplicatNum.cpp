class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int m;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n&&i+1<n;i++){
                if(nums[i]==nums[i+1]){
                m=nums[i];
                break;
                }
            }
        return m;
    }
};
