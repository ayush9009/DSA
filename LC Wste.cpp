int n = nums.size();
        vector<int> ans(n,-1);
        int i=0, flag=0;
        long long sum=0;
        int x=0;
        
        for(  ; i<n; i++){
            if( i-k >= 0 && i+k < n){
                if(flag == 0){
                    while(x < 2*k+1){
                        sum += nums[x];
                        x++;
                    }
                    flag = 1;
                }
                else{
                    sum += nums[i+k];
                    sum -= nums[i-k-1];
                }
                ans[i] = sum/(2*k+1);  
            }
        }
        return ans;
