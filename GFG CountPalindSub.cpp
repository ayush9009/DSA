class Solution {
public:
    const long long int mod = 1000000007;
    long long int add(long long int x, long long int y) {
        return ((x % mod) + (y % mod)) % mod;
    }
    long long int sub(long long int x, long long int y) {
        return ((x % mod) - (y % mod) + mod) % mod;
    }
    long long int  countPS(string str)
    {
        long long int  N = str.length();
        long long int  cps[N + 1][N + 1];
        memset(cps, 0 , sizeof(cps));
        for (long long int  i = 0; i < N; i++)cps[i][i] = 1;
        for (long long int  L = 2; L <= N; L++)
        {
            for (long long int  i = 0; i <= N - L; i++)
            {
                long long int  k = L + i - 1;
                if (str[i] == str[k])
                    cps[i][k] = add(cps[i][k - 1] , add(cps[i + 1][k] , 1LL)) % mod;
                else
                    cps[i][k] = add(cps[i][k - 1] , sub(cps[i + 1][k] , cps[i + 1][k - 1])) % mod;
            }
        }
        return cps[0][N - 1] % mod;
    }
}; 
