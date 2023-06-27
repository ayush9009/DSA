class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        if(len <= 1){
            return {strs};
        }
        unordered_map<string, vector<string>> mp;
        string temp;
        for(int i=0; i<len; i++){
            temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it){
            ans.push_back(it->second);   
        }
        return ans;
    }
};
