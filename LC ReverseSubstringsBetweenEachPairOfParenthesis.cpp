class Solution {
public:
    string reverseParentheses(string s) {
        string result="";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            string str="";
            if(!st.empty() && s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    str+=st.top();
                    cout<<st.top()<<" ";
                    st.pop();
                }
                if( !st.empty() && st.top()=='('){
                    st.pop();
                    
                // if(str.size()!=0){
                    cout<<str<<" ";
                    for(int i=0;i<str.size();i++)st.push(str[i]);
                }
            } 
            else st.push(s[i]);
        }
        if(!st.empty() && st.top()==')')st.pop();
           while(!st.empty() ){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

