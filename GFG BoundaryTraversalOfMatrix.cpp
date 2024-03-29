class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > mat, int n, int m) 
    {
        vector<int>ans;
        for(int i=0;i<m;i++) ans.push_back(mat[0][i]);
        for(int i=1;i<n;i++) ans.push_back(mat[i][m-1]);
        if(n!=1) for(int i=m-2;i>=0;i--) ans.push_back(mat[n-1][i]);
        if(m!=1) for(int i=n-2;i>0;i--) ans.push_back(mat[i][0]);
        return ans;
    }
};
