class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int Max=0,len;
        st.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push(i);
            else{
                st.pop();
                if(st.empty())
                    st.push(i);
                else{
                    len=i-st.top();
                    Max=max(Max,len);
            }
        }
        }
            return Max;
    }
};