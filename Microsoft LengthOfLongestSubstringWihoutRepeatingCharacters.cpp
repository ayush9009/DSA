//NIceee qeustion
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        unordered_map<char,int>mp;
        int maxi=0,lastUniquIndex=0;
        for(int i=0;i<s.size();i++){
            char key=s[i];
            if(mp.count(key)>0)lastUniquIndex=max(lastUniquIndex,mp[key]+1);
            mp[key]=i;
            maxi=max(maxi,i-lastUniquIndex+1);
        }
        return maxi;
        
    }
};
