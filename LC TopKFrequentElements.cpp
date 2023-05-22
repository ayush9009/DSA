class Solution {
public:
    typedef pair<int,int>pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int>result;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int>>>pq;
        priority_queue<pi, vector<pi>, greater<pi> >pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k)pq.pop();
        }
        while(pq.empty()==false){
            result.push_back(pq.top().second);
            pq.pop();
        }
       
        return result;
    }
};
