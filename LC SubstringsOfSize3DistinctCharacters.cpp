class Solution {
public:
    int countGoodSubstrings(string s) {
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         st.insert(s[i]);
        //         if(st.size()==3 && (i+1)%3==0){
        //             cnt++;
        //             st.clear();
        //         }
        //     }
        // }
        // return cnt;
        vector<string>res;
        int n=s.size();
        for (int len = 1; len <= n; len++) { // Length of substring
        for (int i = 0; i <= n - len; i++) { // Starting index of substring
            string str = s.substr(i, len);
            if(str.size()==3)res.push_back(str);
        }
       }
        int cnt=0;
        unordered_set<char>st;
        for(auto it:res){
            cout<<it<<endl;
            for(auto x:it)st.insert(x);
            if(st.size()==3)cnt++;
            st.clear();
        }
        return cnt;
    }
};
