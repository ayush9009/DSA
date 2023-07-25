class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int n=text.size();
        if(n==0)return -1;
        int m=pat.size();
        if(m==0)return 0;
        return text.find(pat);
    }
};
