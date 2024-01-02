class Solution {
public:
    void reverseString(vector<char>& s) {
    //    reverse(s.begin(),s.end());
       vector<char>str=s;
       s.clear();
       for(int i=str.size()-1;i>=0;i--)s.push_back(str[i]);
    }
};
