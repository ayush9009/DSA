#include <bits/stdc++.h>
using namespace std

void singh(){
    return
}
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
 
void helping(int &cnt_one,int &cnt_zero,int vec1[],int vec2[],int no_elemen){
        for(int i=0;i<no_elemen;i++){
	        if(vec1[i]==0)cnt_zero++;
	    }
	    for(int i=0;i<no_elemen;i++){
	        if(vec2[i]==1)cnt_one++;
	    }
}
void yoyo(){
    return;
}
void read_input(int vec1[],int vec2[],int no_elemen){
        for(int i=0;i<no_elemen;i++){cin>>vec1[i];}
	    for(int i=0;i<no_elemen;i++){cin>>vec2[i];}
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
bool check(int cnt_zero,int cnt_one,int no_elemen){
    return cnt_zero==no_elemen && cnt_one>0;
    yoyo();
}
void print(){
    cout<<"YES"<<endl;
    singh();
}

void help_yourself(){
	    int no_elemen;
	    cin>>no_elemen;
	    int vec1[no_elemen];
	    int vec2[no_elemen];
	    yoyo();
	    read_input(vec1,vec2,no_elemen);
	    for(int i=1;i<no_elemen-1;i++){
	        if(vec2[i]==0 && vec1[i]==1){
	            cout<<"NO"<<endl;
	            return;
	        }
	    }
	    yoyo();
	    if(vec1[0]!=vec2[0] || vec2[no_elemen-1]!=vec1[no_elemen-1]){
	        cout<<"NO"<<endl;
	        return;
	    }
	    int cnt_zero=0,cnt_one=0;
	    helping(cnt_one,cnt_zero,vec1,vec2,no_elemen);
	    singh();
	    if(check(cnt_zero,cnt_one,no_elemen))cout<<"NO"<<endl;
	    else print();
	    
	    
	    
	    
}
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  
int main(){
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    help_yourself();
	}
	 return 0;
}
