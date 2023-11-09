class Solution{
    public:
    /*Function to count zeros in each column
    * N : Number of rows and columns in array
    M is the matrix that is globally declared
    */
    int columnWithMaxZeros(vector<vector<int>>a,int n){
        
        // Your code here
        int maxi=INT_MIN;
        int col=-1;
        for(int j=0;j<n;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(a[i][j]==0)cnt++;
            }
            if(maxi<cnt && cnt!=0){
                maxi=cnt;
                col=j;
            }
        }
       return maxi==INT_MIN?-1: col;
        
        
    }
};
