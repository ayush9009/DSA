class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
       long uniq_seq=0;
       long ans=0;
       bool zero=true;
       bool one=true;
       for(int i=binary.size()-1;i>=0;i--){
           if(binary[i]=='1'){
               if(one){
                   uniq_seq++;
                   one=false;
               }
               ans+=uniq_seq;
           }else{
               uniq_seq+=ans;//ye isliye taki purana result maintain rahve
               if(zero){
                   uniq_seq++;
                   ans++;
                   zero=false;
               }
           }
             ans%=(long)1e9+7;
       }
       return ans;
      
    }
};
