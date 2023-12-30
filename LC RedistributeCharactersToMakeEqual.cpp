class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>mp;
        for(auto it:words){
            for(auto t:it){
                mp[t]++;
            }
        }
        int n=words.size();
        for(auto it:mp){
            if(mp[it.first]%n!=0)return false;
        }
        return true;
    }
};
