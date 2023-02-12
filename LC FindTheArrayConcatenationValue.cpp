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
    void helper(long long &agya_bhao,long long &lefts,long long &rights,vector<int>& nums){
         while(lefts<rights){
            string first_string=to_string(nums[lefts]);
            string second_string=to_string(nums[rights]);
            
            string target=first_string+second_string;
            int lala_bhao=stoi(target);
            agya_bhao+=lala_bhao;
            lefts++;
           rights--;
        }
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
    long long findTheArrayConcVal(vector<int>& nums) {
        long long agya_bhao=0;
        long long n=nums.size();
        long long lefts=0,rights=n-1;
        helper(agya_bhao,lefts,rights,nums);
        if(n%2){
            agya_bhao+=nums[n/2];
        }
        return agya_bhao;
    }
};
