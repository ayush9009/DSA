class Solution {
public:
   //badiya
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string>s;
        for(auto it:ideas){
            s.insert(it);
        }
         vector<vector<int>> dp(26, vector<int> (26, 0));
        for(int i=0;i<ideas.size();i++){
            string idea=ideas[i];
            char old_idea=idea[0];
            for(char new_idea='a';new_idea<='z';new_idea++){
                idea[0]=new_idea;
                // cout<<idea<<"hahah<<endl";
                if(s.count(idea)==0){
                    dp[old_idea-'a'][new_idea-'a']++;
                    //ab agr dp[c][a],jabki a hai bhi ideas ki kisi string kai shuru mai
                    //to dp[c][a] 
                    //lakin dp[a][c] kabhi ni aneka to dp[a][c]=0,dp[c][a]=1,to inka prod=0
                    // for example coffee donuts doffee conuts dp[c][d]++
                    //aise hi jab donuts ayega to coffee kai liye deka jaga
                    // tab dp[d][c]++;
                    //tabhi ans=dp[c][d]*dp[d][c] kara va
                    // cout<<dp[old_idea-'a'][new_idea-'a']<<" "<<"tora"<<endl;
                }
            }
        }
            long long cnt=0;
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    
                    cnt+=(long long)dp[i][j]*(long long)dp[j][i];
                    cout<<dp[i][j]*dp[j][i]<<endl;
                }
            }
        return cnt;
    }
};
