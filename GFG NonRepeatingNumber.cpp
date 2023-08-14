class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int>result;
        for(auto it:mp){
            if(it.second==1){
                result.push_back(it.first);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};
