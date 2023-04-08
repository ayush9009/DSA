 vector<int> makeBeautiful(vector<int> arr) {
        stack<int>st;
        for(auto it:arr){
            if(st.size()){
                if(st.top()>=0 && it<0 || st.top()<0 && it>=0){
                    st.pop();
                }else{
                    st.push(it);
                }
            }
            else st.push(it);
        }
        vector<int>result;
        while(st.empty()==false){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
