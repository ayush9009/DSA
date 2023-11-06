class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // code here
                // code here
         vector<int>ans;
        vector<int>dx={0,0,1,1,1,-1,-1,-1};
        vector<int>dy={1,-1,0,-1,1,0,1,-1};
        
        vector<int>dx2={0,1,2,2,2,2,2,1,0,-1,-2,-2,-2,-2,-2,-1};
        vector<int>dy2={-2,-2,-2,-1,0,1,2,2,2,2,2,1,0,-1,-2,-2};
        for(int i=0;i<q;i++){
            int ty=queries[i][0];
            int r=queries[i][1];
            int c=queries[i][2];
            int sum=0;
            if(ty==1){
                for(int i=0;i<8;i++)
                {
                    int row=r+dx[i];
                    int col=c+dy[i];
                    if(row<n&&row>=0&&col<m&&col>=0){
                        sum+=mat[row][col];
                    }
                }
                ans.push_back(sum);
            }else{
                for(int i=0;i<16;i++)
                {
                    int row=r+dx2[i];
                    int col=c+dy2[i];
                    if(row<n&&row>=0&&col<m&&col>=0){
                        sum+=mat[row][col];
                    }
                }
                ans.push_back(sum);
                
            }
        }
        
        return ans;
    }
};
