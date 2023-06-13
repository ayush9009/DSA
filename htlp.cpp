class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        //new concept new concept
//         map of vectors
        // unordered_map<vector<int>int>mp;
        map<vector<int>, int> mp;
        for(auto it:grid){
            mp[it]++;
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            vector<int>result;
            for(int j=0;j<grid.size();j++){
                result.push_back(grid[j][i]);
            }
            count+=mp[result];
        }
        return count;
    }
};
