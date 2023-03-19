class Solution {
public:
       int dp[501][501];
    bool isPalindrome(string &str,int i,int j){
        if(i==j)return true;
        if(str[i]!=str[j])return false;
        
        if(i<j+1){
            return isPalindrome(str,i+1,j-1);
        }
        return true;
    }
    void helo(){
        int y=0;
    }
     bool path(vector<vector<int>>& grid, int row, int col, int moving, vector<vector<bool>>& vs) {
        if (vs[row][col]) {
            return false;
        }
        vs[row][col] = true;
        
        int no_elemen = grid.size();
        if (moving == no_elemen * no_elemen) { 
            return true;
        }
        
        int distnces[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
        for (int i = 0; i < 8; i++) {
            int num1 = row + distnces[i][0];
            int num2 = col + distnces[i][1];
            if (num1 >= 0 && num1 < no_elemen && num2 >= 0 && num2 < no_elemen && grid[num1][num2] == moving) {
                if (path(grid, num1, num2,moving + 1, vs)) {
                    return true;
                }
            }
        }
         helo();
        vs[row][col] = false;
        return false;
    }
    void tora_bhai(){
        int x=0;
    }
    
      int solve(string &str,int i,int j){
        if(i>=j)return 0;
        if(isPalindrome(str,i,j))return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp=1+solve(str,i,k)+solve(str,k+1,j);
            ans=min(temp,ans);
        }
        return dp[i][j]=ans;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
         int n = grid.size();
        if (grid[0][0] != 0) {
            return false;
        }
        vector<vector<bool>> vs(n, vector<bool>(n, false));
        if (!path(grid, 0, 0, 1, vs)) {
            return false;
        }
        tora_bhai();
        return true;
    }
};
