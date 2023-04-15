class Solution {
public:
// If the hashmap at position j has the key diff, it means that there is an arithmetic subsequence ending at index j, with arithmetic difference diff and length dp[j][diff]. And we just add the length by 1. If hashmap does not have the key diff, then those two elements can form a 2-length arithmetic subsequence. And update the result if necessary during the iteration.
    int longestArithSeqLength(vector<int>& nums) {
   // brute force takes O(n^3)->time limit exceeded
     //index diff =count
    //  means dp[index][diff]=count;  //ki is index pai yo diff hai aur ye countofLAS KI
        // if(nums.size()==0)return 0;
        // unordered_map<int,unordered_map<int,int>>dp;
        // int res=2,n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int diff=nums[j]-nums[i];
        //         dp[diff][j]=dp[diff].count(i) ? dp[diff][i]+1:2;
        //         res=max(res,dp[diff][j]);
        //     }
        // }//ye solution bhi tle dera rai baba
        // return res;
        int ans = 2, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2000, 0));
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)  {
                int diff = nums[j] - nums[i] + 1000;//ye 1000,2000 optimisationkai 
                // liye kara nahi to tle ara tha
                dp[j][diff] = max(2, dp[i][diff] + 1);
                ans = max(ans, dp[j][diff]);
            }
        return ans;
    }
};
