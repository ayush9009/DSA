class Solution {
public:
// //apporach:
// here we have replaced all O with X
// but there are some conditions when  we cannot replace O with X
// like if O is on borrder of matrix or 
// or if any of it adjacent is O
// example:
// X O X X  in this case we cannot replace O with X beacuse it's on border
// X O O X  yaha bhi ni kuki its ajdancet zero is on border(i.e i=0 j=1 vali)
// X X O X yaha bhi ni kuki its ajacnet are zeros(i.e i=1,j=1,i=1,j=2 vale)

// X X X X here we can replace O with X 
// X O X X
// X O O X
// X X X X
// what we do here we check only boundary rows and columsn and if they are O 
// so we replace them with # 
// In the end we have three elements #,O,X
// # represents that this element cannnot be replced so we replace it with O
// 0 represents that it can be replace with X so we replace it with X



    void dfs(int i, int j, vector<vector<char>>& board, int n, int m) {
        if (i >= n || j >= m || i < 0 || j < 0 || board[i][j] != 'O') {
            return;
        }
        
        board[i][j] = '#'; 

        dfs(i + 1, j, board, n, m);
        dfs(i, j + 1, board, n, m);
        dfs(i - 1, j, board, n, m);
        dfs(i, j - 1, board, n, m);
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        //first and last column
        //to first and last column to fix hi h i.e j=0,j=n-1 bas row change hori i.e i
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')dfs(i,0,board,n,m);//row kai respect m means row chnagehori
            if(board[i][n-1]=='O')dfs(i,n-1,board,n,m);//m-1 kuki row kai respectmbt hori
        }
        //first and last row
        //to first and last row to fix hi h i.e i=0,i=m-1 bas column change hori i.e j
        for(int j=0;j<n;j++){
            if(board[0][j]=='O')dfs(0,j,board,n,m);
            if(board[m-1][j]=='O')dfs(m-1,j,board,n,m);  //m-1 kuki column kai respectmbt hori
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='#')board[i][j]='O';
            }
        }
    }
};
