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
  
    int mod=1e9+7;
    int waysToReachTarget(int target, vector<vector<int>>& tdso) {
        vector<int>t(target+1);
        t[0]=1;
        for(auto &itert:tdso){
            for(int itert1=target;itert1>=0;itert1--){
                for(int itert2=1;itert2<=itert[0] && itert1-itert2 *itert[1]>=0;itert2++){    //itert1-itert2*iter[1] taki agr value -veya0
                    // ho to pata lag jaye aur phir dusri itertation shuru kar de hum
                    
                    t[itert1]=(t[itert1]+t[itert1-itert2*itert[1]])%mod;
                } 
            }
        }
        return t[target];
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
  
};
