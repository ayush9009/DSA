class Solution {
public:
    int helper(long long int n){
        if(n==1)return 0;
        else if(n%2==0)return 1+helper(n/2);
        else return 1+min(helper(n+1),helper(n-1));
    }
    int integerReplacement(int n) {
       return helper(n);
    }
};
