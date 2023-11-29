class Solution {
public:
    int hammingWeight(uint32_t n) {
      // int ans=0;
      //   while(n!=0)
      //   {
      //       if(n%2==1)
      //           ans+=1;
      //       n/=2;
      //   }
      //   return ans;
        int count=0;
        while(n>0){
            count+=(n&1);
            n>>=1;
        }
        return count;
    }
};
