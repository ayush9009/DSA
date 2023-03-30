class Solution {
public:
    map<string, bool> mp;
    bool solve(string s1, string s2){
        if(s1.size() == 1)
            return s1 == s2;
        if(s1 == s2)
            return true;
        string key = s1+s2;
        if(mp.find(key) != mp.end())
            return mp[key];
        int n = s1.size();
        for(int i=1; i<n; i++){
            if(solve( s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i), s2.substr(i)) || 
            solve(s1.substr(0, i), s2.substr(n-i)) && solve(s1.substr(i), s2.substr(0, n-i)) )
                return mp[key] = true;
        }
        return mp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.size();
        return solve(s1, s2);
    }
};
