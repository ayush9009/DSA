//User function template for C++

class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	   // int flag=0;
	   for(int i=0;i<n;i++){
	       arr[i]=arr[i]*arr[i];
	   }
	   sort(arr,arr+n);
	    int left,right;
	    for(int i=n-1;i-1>=0;i--){
	        left=0;
	        right=i-1;
	        while(left<right){
	            if(arr[left]+arr[right]==arr[i]){
	                return true;
	            }
	            else if(arr[left]+arr[right]>arr[i]){
	                right--;
	            }else{
	                left++;
	            }
	        }
	    }
	    return false;
	}
};
