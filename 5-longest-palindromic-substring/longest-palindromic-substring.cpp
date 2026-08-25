class Solution {
public:
    // string printSubstr(string str,int low,int high){
    //         string result;
    //         for(int i=low;i<=high;i++)result+=str[i];
    //     return result;
                
    // }
    // tc:o(n^2) sc: o(n^2)
    string printingStr(string s,int low,int high){
        // return s.substr(i,j);
        string res;
        for(int i=low;i<=high;i++)res+=s[i];
        return res;
    }
    string longestPalindrome(string s) {
        // int n=s.size();
        // bool dp[n][n];
        // memset(dp,0,sizeof(dp));
        // int maxLen=1;   //initially 1 because all the strings of length 1 are palindrome.
        // for(int i=0;i<n;i++){
        //     dp[i][i]=true;
        // }
        // //ab check for substring of length 2
        // int start=0;   //start isliye lerai kuki print bhi to karnai ki yaha se yaha tak sting print kara do
        // for(int i=0;i<n-1;i++){
        //     if(s[i]==s[i+1]){
        //         dp[i][i+1]=true;i, starting index,i+1 ending index
        //         start=i;
        //         maxLen=2;
        //     }
        // } 
        // //ab check karenge for length greater than 2,here k is lnegth of substring
        // for(int k=3;k<=n;k++){
        //     for(int i=0;i<n-k+1;i++){      //i ->starting index
        //         int j=i+k-1; //get the ending index using starting index and k
        //         if(dp[i+1][j-1]&&s[i]==s[j]){           //pahle starting index elemnt aur ending index element check kar rai phir andar kai using //dp[i+1][j-1]      aabb   to yaha i=0,j=3 to pahle 0,3 match kara phir i+1i.e 1(a) j-1,i.e 2(b)inhe matxh kar rai
        //             dp[i][j]=true;
        //             if(k>maxLen){
        //                 start=i;
        //                 maxLen=k;
        //             }
        //         }
        //     }
        // }
        // return printSubstr(s,start,start+maxLen-1);
        // int n=s.size();
        // // bool dp[n][n];
        // vector<vector<int>>dp(n,vector<int>(n,0));
        // // memset(dp,0,sizeof(dp));
        // int maxLen=1;
        // for(int i=0;i<n;i++){
        //     dp[i][i]=1;
        // }
        // int start=0;
        // for(int i=0;i<n-1;i++){
        //     if(s[i]==s[i+1]){
        //         dp[i][i+1]=true;
        //         maxLen=2;
        //         start=i;
        //     }
        // }
        // for(int k=3;k<=n;k++){ //k repsent length
        //   for(int i=0;i<n-k+1;i++){
        //     int j=i+k-1;
        //     if(dp[i+1][j-1] && s[i]==s[j]){  //pahle last elements compare kar rai ,phir andar kai using i++,j--,dp(i)(j)mewnsyaha de yaha tak true,
        //        dp[i][j]=true;
        //        if(k>maxLen){
        //          maxLen=k;
        //          start=i;
        //        }
        //     }
        //   }
        // }
        // return printingStr(s,start,start+maxLen-1); //starting,ending index,so that we find string
//          int n=s.size();
//         bool dp[n][n];
//         memset(dp,0,sizeof(dp));
//         int maxLen=1;
//         for(int i=0;i<n;i++){
//             dp[i][i]=1;

//         }

//         int start=0;
//         for(int i=0;i<n-1;i++){
//             if(s[i]==s[i+1]){
//                 dp[i][i+1]=1;
//                 start=i;
//                 maxLen=2;
//             }
//         }
//         for(int k = 3; k <= n; k++){
//     for(int i = 0; i <= n - k; i++){
//         int j = i + k - 1;
//         if(dp[i+1][j-1] && s[i] == s[j]){
//             dp[i][j] = true;
//             if(k > maxLen){
//                 maxLen = k;
//                 start = i;
//             }
//         }
//     }
// }

//         return printingStr(s,start,start+maxLen-1);

    //    int n=s.size();
    //    vector<vector<int>>dp(n,vector<int>(n,0)); //iska mtlb yehai ki yaha se yaha tak true,means from i to j, true yani ye valid
    //     for(int i=0;i<n;i++){
    //         dp[i][i]=1;//1 kuki length=1, paldinrome
    //     }
    //    int start=0, maxLen=1;
    //    for(int i=1;i<s.size();i++){
    //      if(s[i]==s[i-1]){
    //         dp[i-1][i]=1;
    //          start=i-1;
    //          maxLen=2;
    //      }
    //    }

       

    //    for(int k=3; k<=n;k++){
    //     for(int i=0;i<=n-k;i++){
    //         int j=i+k-1;
    //         if(dp[i+1][j-1] && s[i]==s[j]){ 
    //             //first last equal,then dp ki madaht se andar vale check hore
    //             dp[i][j]=1;
    //             if(k > maxLen){
    //                 maxLen=k;
    //                 start=i;
    //             }
    //         }
    //     }
    //    }

    //   return s.substr(start,maxLen);

    // int n=s.size();
    // int maxLen=1;
    // int start=0;
    // vector<vector<int>>dp(n,vector<int>(n,0));
    // for(int i=0;i<n;i++)dp[i][i]=1;
    // start=0;
    // for(int i=1;i<n;i++){
    //     if(s[i]==s[i-1]){
    //         dp[i-1][i]=1;
    //         maxLen=2;
    //         start=i-1;
    //     }
    // }
    // for(int k=3;k<=n;k++){
    //     for(int i=0;i<=n-k;i++){
    //         int j=i+k-1;
    //         if(dp[i+1][j-1] && s[i]==s[j]){
    //             // s[i][j] bahar k element i+1,j-1 andar k dek rai
    //             dp[i][j]=1;
    //             if(k>maxLen){
    //                 maxLen=k;
    //                 start=i;
    //             }
    //         }
    //     }
    // }

    // return s.substr(start,maxLen);
    // int n=s.size();
    // int dp[1001][1001];
    // memset(dp, 0, sizeof(dp));
    // int startIdx=0,maxLen=1;
    // for(int i=0;i<n;i++)dp[i][i]=1; //single element to..
    // for(int i=1;i<n;i++){
    //     if(s[i]==s[i-1]){
    //         dp[i-1][i]=1;
    //         maxLen=2;
    //         startIdx=i-1;
    //     }
    // }
    // for(int k=3;k<=n;k++){
    //     for(int i=0;i<=n-k;i++){
    //         int j=i+k-1;
    //         if(dp[i+1][j-1] && s[i]==s[j]){
    //             dp[i][j]=1;
    //             if(k>maxLen){
    //                 maxLen=k;
    //                 startIdx=i;
    //             }
    //         }
    //     }
    // }
    // return s.substr(startIdx,maxLen);

    int dp[1001][1001];
    memset(dp,0,sizeof(dp)); 
    int maxLen=1,startIdx=0;
    int n=s.size();

    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }

    //len=2 palindromes
    //dp[i][j] respent does string s is apldinrome from i to j
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            startIdx=i-1;
            maxLen=2;
            dp[i-1][i]=1;
            
        }
    }

    

    //greater than 2
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j = i+k-1;

            if(dp[i+1][j-1] && s[i]==s[j]){
                dp[i][j]=1;
                if(k > maxLen){
                    maxLen=k;
                    startIdx = i;
                }
            }
        }
    }

    return s.substr(startIdx,maxLen);




      


    }
   
};
    