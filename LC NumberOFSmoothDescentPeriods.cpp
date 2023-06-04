class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long result=1,cnt=1;//since our loop start from 1st index
        int n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i-1]==prices[i]+1)cnt++;
            else cnt=1;
            result+=cnt;
        }
        return result;
    }
};
