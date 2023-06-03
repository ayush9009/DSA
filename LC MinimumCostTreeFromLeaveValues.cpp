class Solution {
public:
    //MATRIX CHAIN  MULITPLICATION KA BADIYA QUESTION BHT BADIYA
    int dp[41][41];
    int mximum_result(vector<int>&arr,int i ,int j){
        int ans=arr[i];
        for(int k=i+1;k<=j;k++){    //DEKO 6 2 4 TO yaha to filhal for i->6,2 values possible hai tomx=6 return hojaga
                                  //aur k+1 to j yani 4 to 4 hi return hoja
                                  //har conition plus karke minimum sum nikal jaga
                                  //is maximm_result function se badiya sa tree bn jaga
            ans=max(arr[k],ans);
        }
        return ans;
    }
    int helper(vector<int>&arr,int i,int j){
        if(i>=j){
            dp[i][j]=0;    //agr i ki value greater than j to testvase fail to usme kuch resut ni to return 0
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int t=helper(arr,i,k)+helper(arr,k+1,j)+mximum_result(arr,i,k)*mximum_result(arr,k+1,j);
            ans=min(t,ans);
        }
        return dp[i][j]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        int n=arr.size();
        return helper(arr,0,n-1);
    }
};
