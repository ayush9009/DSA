class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& arr) {
        int x_diff=arr[1][0]-arr[0][0];
        int y_diff=arr[1][1]-arr[0][1];
          int cur_diff1,cur_diff2;
        for(int i=2;i<arr.size();i++){
             cur_diff1=arr[i][0]-arr[i-1][0];
             cur_diff2=arr[i][1]-arr[i-1][1];
            if(cur_diff2*x_diff !=cur_diff1*y_diff)return false;
        }
        return true;
    }
};
