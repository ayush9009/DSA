class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        vector<long long>prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int mx=0;
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]>0)mx++;
        }
        return mx;
    }
};
