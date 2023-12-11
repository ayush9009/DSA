class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int m;
        int n=arr.size();
        int x=(25*n)/100;
        map<int,int>mp;
        for(auto it:arr)mp[it]++;
        for(auto it:mp){
           if(it.second>x)
           {
               m=it.first;
               break;
           }
        }
        return m;
    }
};
