class Solution {
public:
    int minChanges(string s) {
        int maxi=0;
        int cnt=0;
        for (int i = 1; i < s.size(); i += 2) {
          if (s[i] != s[i - 1]) cnt++;
        }
        return cnt;
    }
};