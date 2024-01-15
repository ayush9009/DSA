class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>m1,m2;
         vector<vector<int>> ans;
        vector<int>result,res;
        for(auto it:matches){
            m2[it[1]]++;
        }
        set<int>s1,s2;
        for(auto it:matches){
            if(m2.find(it[0])==m2.end()){
                s1.insert(it[0]);
            }
            if(m2[it[1]]==1)
            {
                s2.insert(it[1]);
            }
        }
        for(auto it:s1)result.push_back(it);
        for(auto it:s2)res.push_back(it);
        ans.push_back(result);
        ans.push_back(res);
        
        return ans;
    }
};
