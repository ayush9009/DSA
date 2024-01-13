class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>m1,m2;
        for(auto it:s){
            m1[it]++;
        }
        for(auto it:t){
            m2[it]++;
        }
        int cnt=0;
        for(auto it:m1){
            // if(m2.find(it.first)!=m2.end()){
                if(m2[it.first]<it.second){
                    cnt+=abs(m2[it.first]-it.second);
                }
            // }
            // cnt+=it.second;
        }
        return cnt;
    }
};
