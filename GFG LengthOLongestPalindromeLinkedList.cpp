int maxPalindrome(Node *head)
{
    //Your code here
    Node* cur=head;
    // vector<string>s;
    string s;
    while(cur!=NULL){
        s+=(cur->data+'0');
        cur=cur->next;
    }
    int n=s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    // memset(dp,0,sizeof(dp));
    int maxLen=1;
        int start=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;       //jinki length 1 vo to palindrome honge hi
        }
        //now check for length=2;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                maxLen=2;
                start=i;
            }
        }
        //now check for length greater than 3,here k represents length
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j]=1;
                    if(k>maxLen){
                        maxLen=k;
                        start=i;
                    }
                }
            }
        }
        return maxLen;
    
}
