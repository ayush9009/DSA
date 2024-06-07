class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
    
        // Your code here
        int n=a.size()
        int m=b.size();
        if(n>m || n<m)return false
        unordered_map<char,int>mp1,mp2;
        for(auto it:a)mp1[it]++;
        for(auto it:b)mp2[it]++;
        for(auto it:b){
            int x=mp2[it];
            if(mp1.find(it)==mp1.end())return false;
            if(mp2[it]>mp1[it] || mp2[it]<mp1[it])return false;
        }
        return true;
        
    }

};
