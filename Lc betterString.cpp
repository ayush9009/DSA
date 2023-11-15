class Solution {
  public:
    int countSub(string str) {
        // Create an array to store index
        // of last
        vector<int> last(256, -1);

        // Length of input string
        int n = str.length();

        // dp[i] is going to store count of distinct
        // subsequences of length i.
        int dp[n + 1];

        // Empty substring has only one subsequence
        dp[0] = 1;

        // Traverse through all lengths from 1 to n.
        for (int i = 1; i <= n; i++) {
            // Number of subsequences with substring
            // str[0..i-1]
            dp[i] = 2 * dp[i - 1];

            // If current character has appeared
            // before, then remove all subsequences
            // ending with previous occurrence.
            if (last[str[i - 1]] != -1) dp[i] = dp[i] - dp[last[str[i - 1]]];

            // Mark occurrence of current character
            last[str[i - 1]] = (i - 1);
        }

        return dp[n];
    }
    string betterString(string str1, string str2) {
        int a = countSub(str1), b = countSub(str2);
        if (a < b) return str2;
        return str1;
    }
};
