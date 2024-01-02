class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // vector<vector<int>>ans;
        // unordered_map<int,int>mp;
        // for(auto it:nums)mp[it]++;
        // while(mp.size()>0){
        //     unordered_set<int>st;
        //     vector<int>res;
        //     for(auto it:mp){
        //         int t=st.size();
        //         st.insert(it.first);
        //         if(st.size()>t){
        //             mp[it.first]--;
        //             if(mp[it.first]==0)mp.erase(it.first);
        //         }
        //     }
        //     for(auto it:st)res.push_back(it);
        //     ans.push_back(res);
        // }
        // return ans;
             vector<vector<int>> ans;
        unordered_map<int, int> mp;
        
        for (auto it : nums) {
            mp[it]++;
        }
        
        while (!mp.empty()) {
            unordered_set<int> st;
            vector<int> res;
            
            for (auto it = mp.begin(); it != mp.end();) {
                int t = st.size();
                st.insert(it->first);
                
                if (st.size() > t) {
                    res.push_back(it->first);
                    it->second--;

                    if (it->second == 0) {
                        it = mp.erase(it);
                    } else {
                        ++it;
                    }
                } else {
                    ++it;
                }
            }
            
            ans.push_back(res);
        }
        
        return ans;
    }
};
