
class Solution {
public:
    int mod=1000000007;
    int knightDialer(int n) {
        vector<long>cur(10,1);
        vector<long>next=cur;
        for(int i=2;i<=n;i++){
          next[0]=((cur[6]%mod) + (cur[4]%mod))%mod;
          next[1]=((cur[8]%mod) + (cur[6]%mod))%mod;
          next[2]=((cur[7]%mod) + (cur[9]%mod))%mod;
          next[3]=((cur[8]%mod) + (cur[4]%mod))%mod;
          next[4]=((cur[3]%mod) + (cur[9]%mod) + (cur[0]%mod))%mod;
          next[5]=0;
          next[6]=((cur[7]%mod) + (cur[1]%mod) +(cur[0]%mod))%mod;
          next[7]=((cur[2]%mod) + (cur[6]%mod))%mod;
          next[8]=((cur[1]%mod) + (cur[3]%mod))%mod;
          next[9]=((cur[2]%mod) + (cur[4]%mod))%mod;

          cur=next;
        }
        int ans=0;
        for(int i=0;i<10;i++){
          ans=(ans+next[i])%mod;
        }
        return ans;
    }
};
