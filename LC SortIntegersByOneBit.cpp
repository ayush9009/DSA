class Solution {
public:
int CountBits(int n){
    int cnt=0;
    int temp=n;
    while(temp){
        temp&=temp-1;
        cnt++;
    }
    return cnt;
}
   bool static comp(const pair<int,int>&a,const pair<int,int>&b){
      if(a.second==b.second){
          return a.first<b.first;
      }
      return a.second<b.second;
   }
    vector<int> sortByBits(vector<int>& arr) {
       map<int,int>mp;
       vector<pair<int,int>>result;
       for(int i=0;i<arr.size();i++){
            int x=CountBits(arr[i]);
        //    mp[arr[i]]=x;
        result.push_back({arr[i],x});
       }
       sort(result.begin(),result.end(),comp);
       vector<int>ans;
       for(auto it:result){
           ans.push_back(it.first);
       }
       return ans;
    }
};
