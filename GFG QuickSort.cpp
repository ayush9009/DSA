void quickSort(int arr[], int low, int high)
{
    // code here
    if(low<high){
    int pIndex=partition(arr,low,high);
    quickSort(arr,low,pIndex-1);
    quickSort(arr,pIndex+1,high);
    }
    
}
    
int partition (int arr[], int low, int high)
{
   // Your code here
   int pivot=arr[low];
   int i=low;
   int j=high;
   while(i<j){
       while(arr[i]<=pivot && i<=high-1)i++;
       while(arr[j]>pivot && j>=low+1)j--;
       
       if(i<j){
           int temp=arr[i];
           arr[i]=arr[j];
           arr[j]=temp;
        //   swap(arr[i],arr[j]);
       }
       
   }
   int temp=arr[low];
   arr[low]=arr[j];
   arr[j]=temp;
//   swap(arr[low],arr[j]);
   return j;
   
   
}
