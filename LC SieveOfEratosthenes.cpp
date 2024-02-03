class Solution {
public:
    #define ll long long
    vector<bool>sieveOfEratosthenes(ll x){
        vector<bool>primes(x,true);
         primes[0] = primes[1] = false;

    for (int i = 2; i <= sqrt(x); ++i) {
        if (primes[i]) {
            for (int j = i * i; j < x; j += i) {
                primes[j] = false;
            }
        }
    }

    return primes;
    }
    int countPrimes(ll n) {
        if(n<=1)return 0;
        int cnt=0;
        vector<bool>result=sieveOfEratosthenes(n);
        for(ll i=1;i<n;i++) if(result[i])cnt++;
        
        return cnt;
    }
};
