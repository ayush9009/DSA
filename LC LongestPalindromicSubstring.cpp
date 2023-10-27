class Solution {
public:
    string printSubstr(string str,int low,int high){
            string result;
            for(int i=low;i<=high;i++)result+=str[i];
        return result;
                
    }
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[n][n];
        memset(dp,0,sizeof(dp));
        int maxLen=1;   //initially 1 because all the strings of length 1 are palindrome.
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        //ab check for substring of length 2
        int start=0;   //start isliye lerai kuki print bhi to karnai ki yaha se yaha tak sting print kara do
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                start=i;
                maxLen=2;
            }
        } 
        //ab check karenge for length greater than 2,here k is lnegth of substring
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){      //i ->starting index
                int j=i+k-1; //get the ending index using starting index and k
                if(dp[i+1][j-1]&&s[i]==s[j]){           //pahle starting index elemnt aur ending index element check kar rai phir andar kai using //dp[i+1][j-1]      aabb   to yaha i=0,j=3 to pahle 0,3 match kara phir i+1i.e 1(a) j-1,i.e 2(b)inhe matxh kar rai
                    dp[i][j]=true;
                    if(k>maxLen){
                        start=i;
                        maxLen=k;
                    }
                }
            }
        }
        return printSubstr(s,start,start+maxLen-1);
    }
};
