class Solution {
public:
    int mod=1e9+7;
    int numSub(string s) {
       int start=0,end=0,ans=0;
       int n=s.size();
       while(end<n){
           if(s[end]=='0'){
               end+=1;
               start=end;
               continue;
           }else{
               ans+=(end-start+1)%mod;
               ans=ans%mod;
           }

           end++;
       }
       return ans;
    }
};
