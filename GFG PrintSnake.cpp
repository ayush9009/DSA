class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > mat)
    {   
        // code here
        int n=mat.size();
        int flag=1;
        vector<int>result;
        for(int i=0;i<n;i++){
            if(flag){
                for(int j=0;j<n;j++){
                    // cout<<mat[i][j]<<" ";
                    result.push_back(mat[i][j]);
                }
                flag=0;
            }
            else{
                for(int j=n-1;j>=0;j--){
                    // cout<<mat[i][j]<<" ";
                    result.push_back(mat[i][j]);
                }
                flag=1;
            }
        }
        return result;
    }
};
