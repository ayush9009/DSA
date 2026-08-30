class Solution {
public:
    void helper(int i,int j,vector<vector<int>>&visited, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() ||
         grid[i][j]=='0' || visited[i][j]==1)return;
         //agr already visited to ku check kare, agr grid =1 tabhi to land bnega

        visited[i][j]=1;//mark it visited

        //check all 4 directions
        helper(i,j+1,visited,grid);
        helper(i+1,j,visited,grid);
        helper(i-1,j,visited,grid);
        helper(i,j-1,visited,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    helper(i,j,visited,grid);
                    cnt++; //ye ek island cover hogya, ab remaing dekte h
                }
            }
        }
        return cnt;
    }
};