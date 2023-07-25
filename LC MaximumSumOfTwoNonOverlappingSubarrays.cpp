// class Solution {
// public:
// //    Bhatreen question and solution
//     int helper(vector<int>&a,int l,int m,int n){
//         vector<int>Prefix(n+1),suffix(n+1);
//         int sum=0;
//         for(int i=0;i<n;i++){
//             sum+=a[i];
//             Prefix[i+1]=max(Prefix[i],sum);
//             // suppose n=4
//             // 1234567 array   
//             // 0123456  0 base indexing
//             // first we take 1234
//             // now we want to take 2345 sum-= a[3+1-4],that is we remove 1 (0indx sum ,kuki window agey bad gyi ab)
//             if(i+1>=l)sum-=a[i+1-l];
//         }
//         sum=0;
//         for(int i=n-1;i>=0;i--){
//             sum+=a[i];
//             suffix[i]=max(suffix[i+1],sum);
            
//             if(i+1>=m)sum=sum-a[i+m-1];
//         }
//         int res=0;
//         for(int i=0;i<n;i++){
//             res=max(res,Prefix[i]+suffix[i]);
//         }
//         return res;
//     }
//     int maxSumTwoNoOverlap(vector<int>& a, int l, int m) {
//     //    with the help of prefix sum ,we find all pssible sum for fistlen
//     //    with the help of suffix sum,we find all possible sum for secondlen
//     // ab deko len1=2 len2=1 inke result nikal liya
//     // suppose len1={9,1} len2=6 to dono cases dekne padegne yani l,m changeskareke
//     // suppose len1={8,3} len2=9 for get max result
//     return max(helper(a,l,m,a.size()),helper(a,m,l,a.size()));
//     }
// };
class Solution {
public:
    int helper(vector<int>& a, int l, int m, int n) {
        vector<int> prefix(n + 1), suffix(n + 1);
        int sum = 0;

        // Calculate prefix sum
        for (int i = 0; i < n; i++) {
            sum += a[i];
            prefix[i + 1] = max(prefix[i], sum);

            if (i + 1 >= l) // Remove elements outside the l-length window
                sum -= a[i + 1 - l];
        }

        sum = 0;

        // Calculate suffix sum
        for (int i = n - 1; i >= 0; i--) {
            sum += a[i];
            suffix[i] = max(suffix[i + 1], sum);

            if (n - i >= m) // Remove elements outside the m-length window
                sum -= a[i + m - 1];
        }

        int res = 0;

        // Find the maximum sum of non-overlapping subarrays
        for (int i = 0; i < n; i++) {
            res = max(res, prefix[i] + suffix[i]);
        }

        return res;
    }

    int maxSumTwoNoOverlap(vector<int>& a, int l, int m) {
        return max(helper(a, l, m, a.size()), helper(a, m, l, a.size()));
    }
};
