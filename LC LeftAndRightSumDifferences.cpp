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
    vector<int>helper(vector<int> &start,vector<int>& end,vector<int>&result,int no_elemen){
        vector<int>ans;
        for(int itert=1;itert<no_elemen;itert++)start[itert]=start[itert-1]+result[itert-1];
        for(int itert=no_elemen-2;itert>=0;itert--)end[itert]=end[itert+1]+result[itert+1];
        for(int itert=0;itert<no_elemen;itert++){
            ans.push_back(abs(start[itert]-end[itert]));
        }
        return ans;
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
  
    vector<int> leftRigthDifference(vector<int>& result) {
        int no_elemen=result.size();
        vector<int>start(no_elemen);
        vector<int>end(no_elemen);
        start[0]=0;
        end[no_elemen-1]=0;
        return helper(start,end,result,no_elemen);
    }
    void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  
  
};
