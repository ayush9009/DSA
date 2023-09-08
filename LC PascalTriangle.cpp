class Solution {
public:
    vector<vector<int>> generate(int nums) {
    // vector<vector<int>>result;
    //     for(int i=0;i<numRows;i++)
    //     {
    //         vector<int>v(i+1,1);
    //         for(int j=1;j<i;j++)
    //         {
    //             v[j]=result[i-1][j]+result[i-1][j-1];
    //         }
    //         result.push_back(v);
    //     }
    //     return result;
        vector<vector<int>>result;
        for(int i=0;i<nums;i++){
            vector<int>v(i+1,1);
            for(int j=1;j<i;j++){
                v[j]=result[i-1][j-1]+result[i-1][j];
            }
            result.push_back(v);
        }
        return result;
    }
};
