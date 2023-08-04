class Solution {
public:
    //Google
    //BHT Hi Bhatreen question
    unordered_set<string>st;
    int dictionaryContains(string word){
        return st.find(word)!=st.end();
    }
    int wb(string &str){
        if(str.size()==0)return true;
        int dp[str.size()+1];
        memset(dp,0,sizeof(dp));
        //agr len 0 to true hogi dp[lenght of string] to dp[n] agr true to yani word segmented hosakta hai mtlb true return kar do
        dp[0]=true; 
        // len=1 yani i=0,len=2 yani i=0,1,len=3 yani i=0,1,2 and aise baki yo kai liye
        for(int len=1;len<=str.length();len++){
            for(int i=0;i<len;i++){
                if(dp[i] && dictionaryContains(str.substr(i,len-i))){dp[len] =true; break;}
            }
        }
        return dp[str.size()]; //isme dp[n] stor hoga 
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it:wordDict){
            st.insert(it);
        }
        return wb(s);
    }
};
