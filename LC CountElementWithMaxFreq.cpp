class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int maxi=INT_MIN;
        for(auto it:mp){
            if(maxi < it.second ){
                maxi=it.second;
            }
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second==maxi){
                cnt+=it.second;
            }
        }
        return cnt;
    }
};
