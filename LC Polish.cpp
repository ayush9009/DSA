#define ll long long int
class Solution {
public:
    ll convert(string s){
        ll ans=0;
        bool neg=false;
        int i=0;
        if(s[0]=='-'){
            neg=true;
            i++;
        }
        while(i<s.size()){
            ans=ans*10+(s[i++]-'0');
        }
        return neg?-ans:ans;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i=0;i<tokens.size();i++){
            string ch=tokens[i];
            if(ch=="*" || ch=="+" || ch=="/" || ch=="-"){
                ll  b = convert(st.top());
                st.pop();
                ll a = convert(st.top());
                st.pop();
                if(ch=="*") st.push(to_string(a*b));
                else if(ch=="+") st.push(to_string(a+b));
                else if(ch=="/") st.push(to_string(a/b));
                else st.push(to_string(a-b));
            }else st.push(ch);
        }
        return convert(st.top());
    }
};
