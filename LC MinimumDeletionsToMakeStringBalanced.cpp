class Solution {
public:
    int minimumDeletions(string s) {
        // int cnt=0;
        // vector<int>res;
        // stack<char>st;
        // for(int i=s.size()-1;i>=0;i--){
        //     char ch=s[i];
        //     if(!st.empty() && st.top()<ch){
        //         st.pop();
        //         cnt++;
        //     }
        //     else st.push(ch);
        // }
        // return cnt;
        int cnt=0;
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
           if(!st.empty() && (st.top()=='b' && s[i]=='a')){
               st.pop();
               cnt++;
           }else{
               st.push(s[i]);
           }
        }
        return cnt;

    }
};
