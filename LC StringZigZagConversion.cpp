class Solution {
public:
    string convert(string s, int k) {
        vector<string>ans(k,"");
        int i=0;
        int n=s.size();
        while(i<n){
            for(int j=0;j<k&&i<n;j++){
                ans[j]+=s[i++];
            }
            for(int j=k-2;j>=1 && i<n;j--){
                ans[j]+=s[i++];
            }
        }
        string result;
        for(auto it:ans){
            result+=it;
        }
        return result;
    }
};
