class Solution {
public:
    int minOperations(vector<int>& nums) {
      unordered_map<int,int>mp;
      
      for(auto it:nums){
          mp[it]++;
      }
      int cnt=0,sum=0;
      for(auto it:mp){
          if(it.second==1)return -1;
          int x=it.second;
          sum+=x/3;
          x=x-(x/3)*3;
          sum+=(x+1)/2;
      }  
      return sum;
        
     
    }
};
