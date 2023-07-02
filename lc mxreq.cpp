class Solution {
public:

    typedef vector<int> vi;
    int solve(int idx, vector<vi>& req, vi& ans){
        if(idx == req.size()){
            for(auto it : ans) if(it != 0) return INT_MIN;
            return 0;
        }

        int not_pick = solve(idx+1, req, ans);
        ans[req[idx][0]]--;
        ans[req[idx][1]]++;
        int pick = 1 + solve(idx+1, req, ans);
        ans[req[idx][0]]++;
        ans[req[idx][1]]--;

        return max(pick, not_pick); 
    }

    int maximumRequests(int n, vector<vector<int>>& req) {
        vi ans(n, 0);
        
        return solve(0, req, ans);
    }
};
