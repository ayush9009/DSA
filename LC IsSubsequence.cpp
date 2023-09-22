class Solution {
public:
    bool isSubsequence(string s, string t) {
      //      if(s == t)
      // return true;
      // int n = t.size();
      // int m = s.size();
      // int j = 0;
      // for(int i = 0; i < n; i++){
      //    if(s[j] == t[i])
      //    j++;
      //    if(j == s.size())
      //    return true;
      // }
      // return false;
        if(s==t)
            return true;
        int n=s.size();
        int m=t.size();
        int j=0;
        for(int i=0;i<m;i++)
        {
            if(s[j]==t[i])
                j++;
            if(j==s.size())
                return true;
        }
        return false;
        // if(s==t)return true;
        // int m=s.size();
        // int n=t.size();
        // int j=0;
        // for(int i=0;i<n;i++){
        //     if(s[i]==t[i]) j++;
        //     if(j==m) return true;
        // }
        // return false;
    }
};
