class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        vector<vector<char>>grid(m,vector<char>(n,'@'));
        if(m-1>=0 && n-1>=0)grid[m-1][n-1]='.';
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(j-1>=0 && grid[i][j-1]=='@'){
                    grid[i][j-1]='.';
                    if(i-1>=0 && grid[i-1][j]=='@'){
                        grid[i-1][j]='#';
                    }
                }else if(i-1>=0 && grid[i-1][j]=='@'){
                     grid[i-1][j]='.';
                    if(j-1>=0 && grid[i][j-1]=='@'){
                        grid[i][j-1]='#';
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            string s="";
            for(int j=0;j<n;j++){
               s.push_back(grid[i][j]);
            }
            ans.push_back(s);
        }
        return ans;
    }
};