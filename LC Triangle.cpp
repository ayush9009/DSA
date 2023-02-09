class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      for(int idx = triangle.size()-2; idx >=0; --idx) 
            for(int jdx = 0; jdx < triangle[idx].size(); ++jdx) 
                triangle[idx][jdx] += min(triangle[idx+1][jdx], triangle[idx+1][jdx+1]);
        return triangle[0][0];
    }
};
