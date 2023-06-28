 long long trappingWater(int arr[], int n){
        // code here
        long long left=0,right=n-1;
        long long leftmax=0,rightmax=0;
        long long ans=0;
        while(left<=right){
            if(arr[left]<=arr[right]){
                if(leftmax<=arr[left])leftmax=arr[left];
                else ans+=leftmax-arr[left];
                left++;
            }else{
                if(rightmax<=arr[right])rightmax=arr[right];
                else ans+=rightmax-arr[right];
                right--;
            }
        }
        return ans;
    }
