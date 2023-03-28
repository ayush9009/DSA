 int solve(int idx, int n, vector<int>& days, vector<int>& costs, vector<int>& dp){
        if(idx == n)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int i = idx;
        int pass1 = costs[0] + solve(i+1, n, days, costs, dp);

        while(i<n && days[i] < days[idx] + 7) i++;
        int pass7 = costs[1] + solve(i, n, days, costs, dp);

        while(i<n && days[i] < days[idx] + 30) i++;
        int pass30 = costs[2] + solve(i, n, days, costs, dp);

        return dp[idx] = min({pass1, pass7, pass30});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(0, n, days, costs, dp);
    }
