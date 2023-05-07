class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
          vector<int>result(obstacles.size()+1, INT_MAX), ans;

        for(auto it : obstacles)   {
            int ind = upper_bound(result.begin(), result.end(), it) - result.begin();
            result[ind] = it;
            ans.push_back(ind+1);
        }

        return ans; 
    }
    
};
