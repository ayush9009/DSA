
class Solution{
    public:
    // function to calculate N*(N+1)/2
    long long countSubarrys(long long n)
    {
        return n * (n + 1) / 2LL;
    }
    
    // function to count the number of sub-arrays with
    // maximum greater then L and less then R.
    long long countSubarrays(int a[], int n, int L, int R)
    {
        long long res = 0;
    
        // exc is going to store count of elements
        // smaller than L in current valid subarray.
        // inc is going to store count of elements
        // smaller than or equal to R.
        long long exc = 0, inc = 0;
    
        // traverse through all elements of the array
        for (int i = 0; i < n; i++) {
    
            // If the element is greater than R,
            // add current value to result and reset
            // values of exc and inc.
            if (a[i] > R) {
                res += (countSubarrys(inc) - countSubarrys(exc));
                inc = 0;
                exc = 0;
            }
    
            // if it is less than L, then it is included
            // in the sub-arrays
            else if (a[i] < L) {
                exc++;
                inc++;
            }
    
            // if >= L and <= R, then count of
            // subarrays formed by previous chunk
            // of elements formed by only smaller
            // elements is reduced from result.
            else {
                res -= countSubarrys(exc);
                exc = 0;
                inc++;
            }
        }
    
        // Update result.
        res += (countSubarrys(inc) - countSubarrys(exc));
    
        // returns the count of sub-arrays
        return res;
    }
};
