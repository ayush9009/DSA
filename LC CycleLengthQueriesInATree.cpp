class Solution {
public: 
//    obeservation+logic
// Badiya question observation wise
// Dry run       [5,3] cnt=1
//         a=5,b=3
//         while(a!=b){
//             5>3 so a=5/2,a=2 cnt++ i.e cnt=2
//             3>2 so b=3/2 b=1 cnt++ i.e cnt=3
//             2>1 so a=2/2 a=1 cnt++ i.e cnt=4
//             now a==b i.e 1==1 so loop breaks and we push cnt=4 in ans
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it:queries){
            int a=it[0],b=it[1],cnt=1;
            while(a!=b){  //kuki cycle hai,to ek time pai to dono equal ho jange
               if(a>b){
                   a/=2;
                   cnt++;
               } else if(b>a){
                   b/=2;
                   cnt++;
               }
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};
