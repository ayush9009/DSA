class Solution {
public:

    int longestSubsequence(string s, int k) {
       int val=0,base=0;
       int cnt=0;
       for(int i=s.size()-1;i>=0;i--){
           if(s[i]=='1' && val+pow(2,base)<=k){
               val+=pow(2,base);
               cnt++;
           }else if(s[i]=='0')cnt++;

           base++;
       }
       return cnt;
    }
};
