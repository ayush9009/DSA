class Solution{
  public:
    int Countpair(int arr[], int n, int sum){
        
        // Complete the function
        int cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(sum-arr[i])!=mp.end())cnt++;
            mp[arr[i]]++;
        }
        return (cnt==0)?-1:cnt;
    
        
    }
};
