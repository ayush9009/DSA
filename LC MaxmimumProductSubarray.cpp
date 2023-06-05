
class Solution{
public:

	long long maxProduct(vector<int> arr, int n) {
	  
     long long ans=INT_MIN;
     long long prod=1;
     for(int i=0;i<n;i++){
         prod*=arr[i];
         ans=max(ans,prod);
         if(arr[i]==0)prod=1;
     }
     prod=1;
     for(int i=n-1;i>=0;i--){
         prod*=arr[i];
         ans=max(ans,prod);
         if(arr[i]==0)prod=1;
     }
     return ans;
	}
};
