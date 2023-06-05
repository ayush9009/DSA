class Solution {
public:

    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=1;
        int mx=INT_MIN,mn=INT_MAX;
        for(auto &it:nums){
            mx=max(it,mx);
            mn=min(it,mn);
            if(mx-mn>k){
                cnt++;
                mx=mn=it;
            }
        }
        return cnt;
    }
};
