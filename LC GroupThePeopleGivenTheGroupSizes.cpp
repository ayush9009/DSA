class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<g.size();i++){
            mp[g[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            cout<<it.first<<"-> ";
            for(auto t:it.second)cout<<t<<" ";
            cout<<endl;
        }
        for(auto it:mp){
            vector<int>result=it.second;
            int n=result.size()/it.first;
            while(n--){
                vector<int>tora;
                int m=result.size();
                int cnt=0;
                for(int i=0;i<m && cnt!=it.first;i++){
                    tora.push_back(result[m-i-1]);
                    cnt++;
                    result.pop_back();
                }
                reverse(tora.begin(),tora.end());
                ans.push_back(tora);
            }
        }
        // sort(ans.begin(),ans.end(),comp);
        return ans;
    }
};
