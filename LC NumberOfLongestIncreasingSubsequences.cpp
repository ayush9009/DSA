class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        vector<int>lis(n,0);
        vector<int>cnt(n,1);
        int maxi=1;
        // int count[n]={1};
        lis[0]=1;
        int ans=0;
        for(int i=1;i<arr.size();i++){
            lis[i]=1;
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    if(lis[i]<lis[j]+1){
                        // mp[i].push_back(arr[j]);
                        lis[i]=lis[j]+1;
                        cnt[i]=cnt[j];
                        // cnt++;
                        
                    }
                    else if(lis[i]==lis[j]+1){
                        cnt[i]+=cnt[j];
                    }
                }
            }
            if(maxi<lis[i])maxi=lis[i];
        }
        for(int i=0;i<n;i++){
            if(lis[i]==maxi){
                ans+=cnt[i];
            }
        }
       return ans;
        // return cnt;
    }
};
