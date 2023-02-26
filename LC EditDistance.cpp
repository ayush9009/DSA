class Solution {
public:
    // int ed(string s1,string s2,int m,int n){    // DP solution (tabulation method)
    //     int dp[m+1][n+1];
    //     for(int i=0;i<=m;i++)
    //         dp[i][0]=i;
    //     for(int j=0;j<=n;j++)
    //         dp[0][j]=j;
    //     for(int i=1;i<=m;i++){
    //         for(int j=1;j<=n;j++){
    //             if(s1[i-1]==s2[j-1])
    //                 dp[i][j]=dp[i-1][j-1];
    //             else
    //                 dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
    //         }
    //     }
    //     return dp[m][n];
    // }
    // Striver Tabulation Solution 
    //horse ros agr i e par hai aur for ros j s par hai aur hum insert kar rai to horses yani i to e pi hia aur j-1 karna padega 
    // baki string ko check karne kai liye
    //agr replace operation lagaye to e rplace with s to ab i-1 bhi karo aur j-1 baki string to ab i-1,j-1 kai liye hi hoga
    //agr delete karo (horse )mai e ko i-1 karna padag aur kuki delete kar a to j ko to cheda ni to i-1,j
    //ab socho s1="" empty s2="rose" humne se match kar liya tha s1 kai sath lakin ab s1 khtm hogi aur j in rose mai o pai hai yani 
    // index 1 pai to s1 empty s2=ro kai sath match karna to 2 insert karne padega i.e j+1
    //ab socho s1="hor" aur s2="" ab s1 ko s2 se match karna aur s1 mai i (i=2)r pai to kitne delete karun 3 i.e i+1 
    // int ed(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
    //     if(i<0)return j+1; //s1 empty hogyi
    //     if(j<0)return i+1;//s2 empty hogyi
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(s1[i]==s2[j])return dp[i][j]=ed(i-1,j-1,s1,s2,dp);
    //     else{
    //         return dp[i][j]=1+min(ed(i-1,j,s1,s2,dp),min(ed(i,j-1,s1,s2,dp),ed(i-1,j-1,s1,s2,dp)));
    //     }
    //ab ise 1 indexing mai convert karna to kaise kare,i=-1 for s1 and j=-1 for s2 possible hai i,j ki to inhe i<0 ki bajaye i==0 returnj
    //aur j=0 to reutrn i,s1[i-1]==s2[j-1] itne bar karne se 1 indexing ho jagi to ab m+1,n+1
    // }
    //TABULATION OPTIMISED APPROACH(striver)
    int ed(int m,int n,string &s1,string &s2){
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            dp[i][0]=i;  //jiase if i<0 tha in 0 indexing mai to 1 indexing mai i==0 to returnj(yani i kuch bhi ho return j karo)
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else 
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])); //insert,delete,replace
            }
        }
        return dp[m][n];
    }
    int minDistance(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        return ed(m,n,s1,s2);
    }
};
