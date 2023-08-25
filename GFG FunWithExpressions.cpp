class Solution {
public:
    int calculate(string s) {
        // Code 
        stack<int>st;
        long long int cur=0,sum=0;
        s+='+';
        char sign='+';
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]))cur=cur*10+s[i]-'0';
            else if(s[i]=='+' || s[i] =='-' || s[i]=='*' || s[i]=='/'){
                if(sign=='+'){
                    st.push(+cur);
                }else if(sign=='-'){
                    st.push(cur*(-1));
                }else if(sign=='*'){
                   int num=st.top();st.pop();
                   st.push(cur*num);
                }else if(sign=='/'){
                   int num=st.top();st.pop();
                   st.push(num/cur);
                }
                sign=s[i];
                cur=0;
            }
        }
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};
