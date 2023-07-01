class Solution {
public:
   vector<int>result;
   int ans;
   void helper(vector<int>&cookies,int k,int idx){
       if(idx==cookies.size()){
           int tmp=INT_MIN;
           for(int i=0;i<k;i++){
               tmp=max(tmp,result[i]);
           }
           ans=min(ans,tmp);
           return;
       }
       for(int i=0;i<k;i++){
           result[i]+=cookies[idx];
           helper(cookies,k,idx+1);
           result[i]-=cookies[idx];
       }
   }
    int distributeCookies(vector<int>& cookies, int k) {
        ans=INT_MAX;
        result.resize(k,0);
        helper(cookies,k,0);
        return ans;
    }
};
