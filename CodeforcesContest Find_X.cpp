#include <bits/stdc++.h>
using namespace std;

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

long long Gretest_factpr(long long  aarry1, long long  aarry2)
{
    yoyo();
  if (aarry2== 0)
    return aarry1;
  return Gretest_factpr(aarry2, aarry1 % aarry2);
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
void singh(){
    return;
}
 
// Function to return LCM of two numbers
long long Longest_factor(long long aarry1, long long aarry2)
{
    singh();
    return (aarry1 / Gretest_factpr(aarry1, aarry2)) * aarry2;
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
	    long long aarry1,aarry2,aarry3,aarry4;
        cin>>aarry1>>aarry2>>aarry3>>aarry4;
        singh();
        if((aarry1+1)%aarry2==(aarry3+1)%aarry4){
            yoyo();
            cout<<1<<endl;
            continue;
        }
        long long ting_ting=Longest_factor(aarry2,aarry4) ;
        yoyo();
        cout<<ting_ting - (aarry1%aarry2)<<endl;
        singh();
	}
	return 0;
}
    
