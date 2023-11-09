class Solution {
public:
    // int cnt=0;
    //    map<string,int>mp;
    // void helper(string s,int i,string str){
    //     if(i==s.size()){
    //         // cnt+=str.size();
    //         if(str.size()>1)mp[str]++;

    //         str="";
    //         return ;
    //     }
    //     if(str.size()==0)str+=s[i];
    //     else{
    //         char ch=str[0];
    //         if(ch!=s[i]){
    //             // cnt+=str.size();
    //             if(str.size()>1)mp[str]++;

    //             str="";
    //             return ;
    //         }else{
    //             if(str.size()>1)mp[str]++;
    //             str=str + s[i];
    //         }
    //     }
    //     helper(s,i+1,str);
    // }
    int countHomogenous(string s) {
    //     string str="";
     
    //     for(int i=0;i<s.size();i++){
    //          string st="";
    //          st=st+s[i];
    //         //  cout<<st<<" ";
    //          mp[st]++;
    //     }
    //     // for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
    //     for(int i=0;i<s.size();i++){
    //         helper(s,i,str);
    //     }
    //    for(auto it:mp)cnt+=it.second;
    //     return cnt;
    map<char,int>mp;
    int mod=1e9+7;
    int cnt=0;
    mp[s[0]]++;
    cnt+=1;
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]){
            mp.erase(s[i-1]);
            mp[s[i]]++;
            cnt+=1;
        }else{
            mp[s[i]]++;
            cnt+=mp[s[i]];
            cnt=cnt%mod;
        }
    }
    return cnt;
        
    }
};
