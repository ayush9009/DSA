// #define int long long
class Solution {
public:
    // intially ans=-1,prod=-1 recursive dfs approach
    // long long helper(vector<vector<int>>&gr,int i,int j,int n,int m ,int ans,int prod ){
    //     if(gr[i][j]==0){
    //         ans=max(ans,0);
    //         return;
    //     }
    //     if(i==n-1 || j==m-1 ){
    //         ans=max(ans,prod);
    //     }
    //     prod=prod*gr[i][j];

    //     if(i+1<n) helper(gr,i+1,j,n,m,ans,prod);
    //     if(j+1<m) helper(gr,i,j+1,n,m,ans,prod);
               
    // }
    //  int maxProductPath(vector<vector<int>>& gr) {
    //     int n=gr.size();
    //     int m=gr[0].size();
    //     int ans=-1,prod=-1;
    //     helper(gr,0,0,n,m,ans,prod)
    //     return ans;
    //  }
    
    // OPTIMISED DP APPROACH,BAHATREEN QUESTION (MAX PROD IN SUBARRAY KA ADVANCED VERSION HAI)
    int maxProductPath(vector<vector<int>>& gr) {
        int n=gr.size();
        int m=gr[0].size();
        // mx,mn isliye jaraort hai ki :
        // mx mai postive result hai(maxvalue)
        // mn mai negative reuslt hai(maxvalue)? 

        vector<vector<long long int>>mx(n,vector<long long int>(m,0));
        vector<vector<long long int>>mn(n,vector<long long int>(m,0));
        

        mx[0][0]=gr[0][0];
        mn[0][0]=gr[0][0];
        for(int i=1;i<n;i++){//aise initially hora har row kai element ka in mx and mn(formaxvalueandmnvalue)
            mx[i][0]=mx[i-1][0]*gr[i][0];
            mn[i][0]=mn[i-1][0]*gr[i][0];
        }
        for(int j=1;j<m;j++){
            mx[0][j]=mx[0][j-1]*gr[0][j];
            mn[0][j]=mn[0][j-1]*gr[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(gr[i][j]>=0){//mx stores maximum prod and mn gives min prod
                    mx[i][j]=max({(long long int)mx[i-1][j] * gr[i][j] , (long long int)mx[i][j-1] * gr[i][j]});
                    mn[i][j]=min({(long long int)mn[i-1][j] * gr[i][j] , (long long int)mn[i][j-1] * gr[i][j]});
                }
                else{//here mn gives maximum prod and mx givs mini prod
                    mn[i][j]=min({(long long int)mx[i-1][j] * gr[i][j] , (long long int)mx[i][j-1] * gr[i][j]});
                    mx[i][j]=max({(long long int)mn[i-1][j] * gr[i][j] , (long long int)mn[i][j-1] * gr[i][j]});
                }
            }
        }
        if(mx[n-1][m-1] < 0)return -1;
        else return mx[n-1][m-1]%1000000007;
    }
};
