class Solution {
public:
    int addMinimum(string word) {
    //  unordered_map<char,int>mp;
    //     for(auto it:word){
    //         mp[it]++;
    //     }
    //     int mx=INT_MIN;
    //     for(auto it:mp){
    //         if(mx<it.second)mx=it.second;
    //     }
    //     return 3*mx-word.size();
    int result=0,n=word.size();
    int i=0;
    while(i<n){
        int cnt=0;
        if(word[i]=='a'){
            cnt++;i++;
        }
        if(word[i]=='b' && i<n){
            cnt++;
            i++;
        }
        if(word[i]=='c' && i<n){
            cnt++;
            i++;
        }
        result+=3-cnt; //kuki abc length 3 aur utne ki hume jaroat h
    }
    return result;
    }
};
