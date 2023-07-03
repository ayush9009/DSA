class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())return false;
        vector<int>result;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                c++;
                result.push_back(i);
            }
        }
        if(c==2){
            int i=result[0];
            int j=result[1];
            if(s[i]==goal[j] && s[j]==goal[i])return true;
            return false;
        }
        else if(c==0){
           map<char,int>mp;
            for(int i=0;i<s.size();i++){
                // freq[s[i]-'a']++;
                // if(freq[s[i]-'a'])
                mp[s[i]]++;
                if(mp[s[i]]>1)return true;
            }
                return false;
        }
       return false;
    }
};
