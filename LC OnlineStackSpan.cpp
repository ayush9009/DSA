#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int,int>>st;
    vector<int>result;
    for(int i=0;i<price.size();i++){
        int cnt=1;
        while(st.empty()==false && price[i]>=st.top().first){
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price[i],cnt});
        result.push_back(cnt);
    }
    return result;
}
