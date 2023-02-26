class Solution {
public:
    void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; //temporary arrays  
      
    /* copy data to temp arrays */  
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
      
    i = 0; /* initial index of first sub-array */  
    j = 0; /* initial index of second sub-array */   
    k = beg;  /* initial index of merged sub-array */  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
    void update1(multiset<int>&mota_paisa,vector<int>&result){
         for(auto it: result)
          mota_paisa.insert(it);
    }
    void mergeSort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
} 
    void update2(vector<int>& result){
         sort(result.begin(),result.end());
    }
    void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  
  
    void update3(int no_elemen,int &inde_ing){
         inde_ing=no_elemen/2-1;
    }
    void update5(int &tora_bahi){
        tora_bahi += 2;
    }
    int partition (int a[], int start, int end)  
{  
    int pivot = a[end]; // pivot element  
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (a[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}  
  
    void update4(int &inde_ing){
        inde_ing--;
    }
    void quick(int a[], int start, int end) /* a[] = array to be sorted, start = Starting index, end = Ending index */  
{  
    if (start < end)  
    {  
        int p = partition(a, start, end); //p is the partitioning index  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}  
    int helper(vector<int>&result,int &no_elemen){
        multiset<int>mota_paisa;
        update1(mota_paisa,result);
        update2(result);
        int inde_ing =no_elemen/2-1;
        int tora_bahi = 0;
        while(inde_ing >= 0){
           auto happy = mota_paisa.lower_bound(2*result[inde_ing]); 
           if(happy == mota_paisa.end()){
               update4(inde_ing);
               continue;
           } 
              // /tora_bahi += 2;
              update5( tora_bahi);
              auto hello = mota_paisa.find(result[inde_ing]);
              mota_paisa.erase(hello);
              mota_paisa.erase(happy);    
            inde_ing--;   
        }
        return tora_bahi;
    }
    void printArr(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
      int maxNumOfMarkedIndices(vector<int>& result) {
          int no_elemen=result.size();
          return helper(result,no_elemen);
      }
   
};
