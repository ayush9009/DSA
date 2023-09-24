class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> ans;
        map<int,int>mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        for(auto it:mp){
            if(it.second>1) ans.push_back(it.first);
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }


};
