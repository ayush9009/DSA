class Solution {
public:
//    BOHOT JADA KADAK QUESTION BAHATREEN FEEL VAALA QUESTION
// yad rakna agr bottom up approach lagani hove to opposite hija 
// bootom up mai i deko 1-n jara yani expand hora aur j shrink hora pasas ata jave to inka opposite lena bottom up mai
// memoistation code
    int helper(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;
        for(int ind=i;ind<=j;ind++){
            int cost=cuts[j+1]-cuts[i-1]+helper(i,ind-1,cuts,dp)+helper(ind+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        // ye insert shurumai akri mai isliye kara taki length nikal sake subcases stick ki jiske madath se cost nikalegi
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return helper(1,c,cuts,dp);
    }
    // 0 1 2 3 4 5 6 to suppose length is 6 and u make cut at 3 and u start from 1 to 5 to len=len(j+1)-len(i-1)i.e 6-0 is length
    // to phir hum 0-3 se tak and 3-6 tak solve karlenge to cost=cuts[j+1]-cuts[i-1]+f(i,ind-1)+f(ind+1,j)
    // yaha cost hai length of stick 
    // ab manlo 0 1 3 4 5 6 cut mara 4 pai to hum lenge ek taraf 0 1 3 4 aur ek taraf 4 5 6 ab 5 pai mara to 4 5 and 5 6 to 
    // cost kya ari saaf dik ra lent of stick +f(ind-1)+f(iind+1,j) aise ho jaga
    // ind-1 and ind+1 kuki ind pai to kat mara aur uski length lelo
    // yaha dekni vali bat hai sorted hona bht jarari manlo 4 2 7 6 1 now u make a cut on 7 to 4 2 7 and 7 6 1 to 1 is depenendton 427(kuki1 isme ayega na ki 761 mai to,ye independet honac choaye uske liye sorint bht jarori hai)
};
