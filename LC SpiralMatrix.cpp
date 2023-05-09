class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int sR=0,sC=0;
        int eR=row-1,eC=col-1;
        int count=0;
        int total=row*col;
        vector<int>ans;
        while(count<total){
            for(int i=sC;count<total && i<=eC;i++){
                ans.push_back(mat[sR][i]);
                count++;
            }
            sR++;
            for(int i=sR;count<total && i<=eR;i++){
                ans.push_back(mat[i][eC]);
                count++;
            }
            eC--;
            for(int i=eC;count<total && i>=sC;i--){
                ans.push_back(mat[eR][i]);
                count++;
            }
            eR--;
            for(int i=eR;count<total && i>=sR;i--){
                ans.push_back(mat[i][sC]);
                count++;
            }
            sC++;
        }
        return ans;
    }
   
};
