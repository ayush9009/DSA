class Solution
{
  public:
     long long int solve(string s,int k){
        int i = 0;
        int j = 0 ;
        int n = s.length() ; 
        vector<int>charFreq(26,0); 
        int dist_count = 0 ;
        long ans = 0 ;
        while(j<n){
            charFreq[s[j]-'a']++;
            if(charFreq[s[j]-'a']==1){ //Distinct Character
                dist_count++;
            }
            //Decreasing Window Size 
            while(dist_count>k){
                charFreq[s[i]-'a']--;
                if(charFreq[s[i]-'a']==0){
                    dist_count--;
                }
                i++;
            }
            j++;
            ans+=(j-i+1) ; 
        }
        return ans ;
    }
    long long int substrCount(string S, int K) {
        // your code here
        return solve(S,K)-solve(S,K-1) ;
    }
    
};
