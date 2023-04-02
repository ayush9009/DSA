#include <bits/stdc++.h>
using namespace std

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
  
void yoyo(){
    return;
}
void print(long long first){
    cout<<first<<" ";
    yoyo();
}
void singh(){
    return;
}
void print2(long long second){
    cout<<second<<" ";
}
void helper(long long first,long long second,long long no_elemen){
    singh();
       for(int i=0;i<no_elemen;i++){
	        for(int j=0;j<no_elemen;j++){
	            if(first<=no_elemen*no_elemen){
	                print(first);
	                singh();
	                first=first+2;
	            }else{
	                print2(second);
	                second=second+2;
	            }
	        }
	        yoyo();
	        cout<<endl;
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
void help_yourself(){
	    long long no_elemen;
	    cin>>no_elemen;
	    singh();
	    long long first=1,second=2;
	    helper(first,second,no_elemen);
	    yoyo();
	
}
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  

int main() {
	// your code goes here
	long long t;
	cin>>t;
	while(t--){
	    help_yourself();
	}
	return 0;
}
