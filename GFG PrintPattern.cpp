class Solution{
public:
    vector<int> pattern(int n){
        // code here
        vector<int>result;
        int i=0;
        for( i=n;i>0;i-=5){
            result.push_back(i);
        }
        // result.push_back(i);
        for(int j=i;j<=n;j+=5){
            result.push_back(j);
        }
        return result;
    }
};
