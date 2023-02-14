class Solution {
public:
//    naive apporach->O(n*n) we have do it lesser than this time
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();

        // offline query vala concept use huha yaha pr range sum query vala concept ki hum array nikalenge
        // jisme har element ka pta lag jaga ye kitne steps shift hona,vo kaise niklega
        // deko do variables start end ,(start yani begin kaha se hora end yani particular point ki iseyageynijasakte)
        // start kai sath sath end+1 update hota rahega
        // example se smjo
        // dp(n+1,0)=dp{0,0,0,0}
        // query{0,1,0},itmeans start=0 end=1 decrement operation {-1,0,1,0} ab dp[start]=-1 hona to dp[end+1]=1 (yaniulta)
        // query{1,2,1},start=1,end=2 increment operaiton{-1,1,1,-1} dp[start]=1 hora to dp[end]=-1 kar do
        // query{0,2,1},start=0,end=2 incremnt operaion{0,1,1,0}dp[start]=0 dp[end]=0 0 opposite 0

        // ab prefix array tyar hai lakin ab hume prefic sum array chaiye
        // {0,1,1,0}={0,0+1,0+1+1,0+1+1+0}={0,1,2,2}
        // s=abc shifting a by 0 times i.e s=abc
        // s=abc shifting b by 1 times i.e s=acc
        // s=abc shifting c by 2 times i.e s=ace this is the answer

        vector<int>dp(n+1,0);
        for(auto &it:shifts){
            int start=it[0],end=it[1],diret=it[2];
            if(diret==1){
                ++dp[start];
                --dp[end+1];
            }else if(diret==0){
                   --dp[start];
                   ++dp[end+1];
            }
        }
        for(int i=1;i<=n;i++){
            dp[i]+=dp[i-1];   //prefix sum array
        }

        for(int i=0;i<n;i++){
            if(dp[i]<0)dp[i]=(-(abs(dp[i])%26)+26)%26;   //handling negative values(tricky)
            s[i]=(char)('a'+ (s[i]-'a' + dp[i] + 26)%26); //shifting vala scene
        }
        return s;
    }
};
