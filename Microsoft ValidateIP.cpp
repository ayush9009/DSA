class Solution {
    public:
        int isValid(string s) {
            // code here
            string str="";
            vector<string>result;
            for(int i=0;i<s.size();i++){
                
                if(s[i]!='.' && s[i]-'0' <10){
                    str+=s[i];
                }else{
                    result.push_back(str);
                    // x=0;
                    str="";
                }
            }
            if(str.size()!=0)result.push_back(str);
            // for(auto it:result){
            //     cout<<it<<endl;
            // }
            if(result.size()<4 || result.size()>4 || s[s.size()-1]=='.')return false;
            for(auto it:result){
                int x=0;
                if(it[0]-'0'==0 && it.size()!=1)return false;
                for(int i=0;i<it.size();i++){
                    x=x*10+it[i]-'0';
                }
                if((x==0  && it.size()!=1) || x>255 )return false;
            }
            return true;
        }
};
