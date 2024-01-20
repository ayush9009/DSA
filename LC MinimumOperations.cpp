class Solution {
public:
    #define pii pair<int,int>
    #define prq priority_queue
    int minimumArrayLength(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        int val=mp.begin()->first;
        int ct=mp.begin()->second;
        mp.erase(mp.begin());
        for(auto x:mp){
            if(x.first%val!=0){
                return 1;
            }
        }
        if(ct%2){
            return 1+(ct-1)/2;
        }else return ct/2;
    }
};
