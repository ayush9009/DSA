class Solution{
    public:
    long long power(int N,int R)
    {
       if(R==0){
           return 1;
       }
       long long ans=power(N,R/2);
    if(R%2==0){
        return (ans*ans)%1000000007;
    }
    else{
        return (N*((ans*ans)%1000000007))%1000000007;
    }
    }
};
