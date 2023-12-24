class Solution {
public:
    int mini(string s){
        int ans=0;
        int n = s.size();
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                ans++;
                if(s[i]=='0') s[i]='1';
                else s[i]='0';
            }
        }
        return ans;
    }
    int minOperations(string s) {
        int n = s.size();
        int ans=mini(s);
        if(s[0]=='0') s[0]='1';
        else s[0]='0';
        ans=min(ans, mini(s)+1);
        return ans;
    }
};
