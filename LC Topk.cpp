class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
       
         vector<int> v;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto x:m)
        {
            q.push({x.second,x.first});
        }
        while(k!=0)
        {
            v.push_back(q.top().second);
            q.pop();
            k--;
        }
        return v;
    }
};
