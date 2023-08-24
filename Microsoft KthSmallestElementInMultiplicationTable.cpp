///VVIP QUESTION OF BINARY SEARCH(Observation required for thinking about logic)
    int KthSmallest(int m, int n, int k) {
        //Write your code here
        int low=1;
        int high=m*n;
        
        while(low<high){
            int mid=low+(high-low)/2;
            int cnt=0;
            for(int i=1;i<=m;i++){
                cnt+=min(mid/i,n);  // cnt the number in particluar row that are smaller than mid
            }
            if(cnt<k)low=mid+1;
            else high=mid;
        }
        return low;
    }
};
