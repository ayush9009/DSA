class Solution {
public:
    int totalFruit(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        int j=0, maxi = 1;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            while(mp.size() >= 3){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
            maxi = max(maxi, i-j+1);
        }
        return maxi;
    }
};
