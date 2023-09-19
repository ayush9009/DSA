int findDuplicate(int arr[])
{
    // Your code goes here
    int m;
    for(int i=0;i<10&&i+1<10;i++){
        if(arr[i]==arr[i+1]){
            m=arr[i];
            break;
        }
    }
    return m;
}
