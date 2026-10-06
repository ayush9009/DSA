class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int cnt=0;
        for(auto it:s){
            cnt++;
           if(it=='(')st.push(it);
           

           if(st.size()>0 && it==')'){
            st.pop();
            cnt-=2;
           }
        }
        return cnt;
    }
};