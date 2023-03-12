class Solution {
public:
    bool check(char c){
        
        return c=='a' || c=='e'|| c=='i' || c=='o' || c=='u' ;
        
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt=0;
        for(int i=left;i<=right;i++){
            if (check(words[i][0]) && check(words[i][words[i].size()-1])) cnt++;
        }
        return cnt;
    }
};
