class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int n=nums.size();
        // int result=0;
        // for(int i=0;i<n;i++){
        //     if(result<i) return false;
        //     result=max(result,i+nums[i]);
        // }
        int n=nums.size();
        int result=0;
        for(int i=0;i<nums.size();i++){
            if(result<i)return false;
            result=max(result,nums[i]+i);
        }
        
        return true;
    }
};
