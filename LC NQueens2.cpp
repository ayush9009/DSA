 bool isSafe(int row,int col,vector<string>&board,int n){
        // vaise queen 8 direction mai attack kare lakinn hum lefttoright chlrai to,agr queen 2 col mai to use3,4 col
        // se khtra ni ho sakta kuki hum board ko fill kar rai left to right,na ki right to left
        // rahi bt queen top ya quuen below to vo bhi ni check hota ,kuki ek col mai ek hi aa sake,
        // to col pai attack left upper diagonal left straight,left lower diagonal se hoga sirf
        int duprow=row;
        int dupcol=col;
        //upper diagonal
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        row=duprow;col=dupcol;
        //straight line
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        //lower diagonal
        row=duprow;col=dupcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }
        return true;
    }
    void func(int col,vector<vector<string>>&ans,vector<string>&board,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){  //ye isliye taki pata lag sake particular mai kis row mai Q ayegi
                board[row][col]='Q';  //is col mai to rak diya
                func(col+1,ans,board,n); //agli col kai liye check karo
                board[row][col]='.';   //backtrack
            }
        }
    }
    int totalNQueens(int n) {
        // vector<vector<string>>ans;
        // vector<string>board(n);
        // string s(n,'.');
        // for(int i=0;i<n;i++){
        //     board[i]=s;
        // }
        // solve(0,board,ans,n);
        // return ans;
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');    //ek string bna di n size ki jime every element . hai
        for(int i=0;i<n;i++){
            board[i]=s;   //har row mai vo string assign kar di
            //aise kar diya
            // ....
            // ....
            // ....
            // ....
        }
        func(0,ans,board,n);
        cout<<ans.size();
        return ans.size();

    }
