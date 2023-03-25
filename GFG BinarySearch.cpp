class Solution {
  public:
    int binarysearch(int arr[], int n, int key) {
        // code here
        int left=0,right=n;
        while(left<right){
            int mid=(left+right)/2;
            
            if(arr[mid]==key){
                return mid;
            }
            else if(arr[mid]>key){
                right=right-1;
            }
            else{
                left=left+1;
            }
        }
        return -1;
    }
};
