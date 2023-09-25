class Solution {
public:
    char findTheDifference(string s, string t) {
        char c;
        int k=0;
        int m=0;
        for(int i=0;i<t.length();i++)
        {
            k=k+(int)t[i];
        }
        for(int i=0;i<s.length();i++)
        m=m+(int)s[i];
        int n=k-m;
        c=(char)n;
        return c;
    }
};
