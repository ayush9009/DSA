
#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int beg, int mid, int end)    
{    
    int i,l, j, k;
    int n1 = mid - beg + 1  ;
    int n2 = end - mid    ;
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
void print4(int rola_bhai_ka){
    cout<<rola_bhai_ka/2<<endl;
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
  
void print5(int rola_bhai_ka){
    cout<<rola_bhai_ka/2+1<<endl;
}
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  
void check_up(int &no_elemen2,int &beast){
        int x=no_elemen2-beast;
        if(x%2==0) print4(x);
        else print5(x);
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
  
bool check(int rola_bhai_ka){
    return rola_bhai_ka%2==0;
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
 
void print1(int musk,int tingin){
     cout<<musk/2+tingin<<endl;
}
void printArr(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
void print2(int musk,int tingin){
    cout<<musk/2+1+tingin<<endl;
}
 vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        int j=n;
        for(int i=0;i<n;i++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            j++;
        }
        return ans;
    }
void printing_press(int &no_elemen2,int &beast,int &tingin){
        int musk=no_elemen2-beast;
        if(check(musk)) print1(musk,tingin);
        else print2(musk,tingin);
}
  string shortestPalindrome(string s) {
        string rev_s=s;
        reverse(rev_s.begin(),rev_s.end());
        string l=s + '#' + rev_s;
        vector<int>p(l.size(),0);
        for(int i=1;i<l.size();i++){
            //update the prefix boundary
            int j=p[i-1];
            while(j>0 && l[i]!=l[j]){
                j=p[j-1];  //move the last prefix boundary match
            }
            //if prefix boundary matches suffix boundary,increase prefix length

            if(l[i]==l[j]){
                p[i]=j+1;
            }
        }
  }
bool check4(int beast){
    return beast%2==0;
}
int minJumps(vector<int>&nums,int n){
       //  if(n==1) return 0;
       //  int res=INT_MAX;
       //  for(int i=0;i<=n-2;i++){
       //      if(i+nums[i]>=n-1){
       //          int sub_res=minJumps(nums,i+1);
       //          if(sub_res!=INT_MAX)
       //              res=min(res,sub_res+1);
       //      }
       //  }
       // return res;
    int dp[n];
        dp[0]=0;
        for(int i=1;i<n;i++)
            dp[i]=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]+j>=i){
                    if(dp[j]!=INT_MAX)
                        dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }

bool check9(int beast,int i){
    return beast%i==0;
}
int jump(vector<int>& nums) {
        int n=nums.size();
        return minJumps(nums,n);
    }
void updte(int &mota_bhai,int &i){mota_bhai=i;}
 bool matching_vectors(vector<int>a,vector<int>b){
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
void updte2(int &beast,int &mota_bhai){beast+=mota_bhai;}
bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return false;
        vector<int>mp1(26,0);
        vector<int>mp2(26,0);
        for(auto it:s1){
            mp1[it-'a']++;
        }
        int i=0,j=0;
        // note:j-i+1 ye isliye kara jara kuki 0 based indexing hai 
        while(j<s2.size()){
            mp2[s2[j]-'a']++;  //store the freq in currentfreqwindow
            if(j-i+1==s1.size()){  //if window size==s1.size then check if window and s1 charcters
            // frequnies are equal or not
                if(matching_vectors(mp1,mp2))return true; //if match directly reutrn true
            }
            if(j-i+1<s1.size())j++;   //if window size less than s1.sizesoincrementthewindowsizei.ej
            else{//means window size is greater than or equal to s1.size()
                mp2[s2[i]-'a']--;  //freq of start decreases
                i++; //make the next window
                j++;
            }
            
        }
        return false;
    }
void help_me(int &tingin,int &beast){
        tingin++;
        int mota_bhai;
        for(int i=2;i<8;i++){
            if(check9(beast,i)){
                updte(mota_bhai,i);
                break;
            }
           
        }
        updte2(beast,mota_bhai);
}
 string convert(string s, int k) {
        vector<string>ans(k,"");
        int i=0;
        int n=s.size();
        while(i<n){
            for(int j=0;j<k&&i<n;j++){
                ans[j]+=s[i++];
            }
            for(int j=k-2;j>=1 && i<n;j--){
                ans[j]+=s[i++];
            }
        }
        string result;
        for(auto it:ans){
            result+=it;
        }
        return result;
    }
void help_yourself(){
    int no_elemen, no_elemen2;
    cin >> no_elemen >> no_elemen2;
    int beast=no_elemen;
    if(check4(beast)){
        int rola_bhai_ka=no_elemen2-beast;
        if(check(rola_bhai_ka)) print4(rola_bhai_ka);
        else print5(rola_bhai_ka);
        
    }
    else
    {
        int tingin=0;
        while(beast%2!=0) help_me(tingin,beast);
        printing_press(no_elemen2,beast,tingin);
    }
    
}
 int minimumTotal(vector<vector<int>>& triangle) {
      for(int idx = triangle.size()-2; idx >=0; --idx) 
            for(int jdx = 0; jdx < triangle[idx].size(); ++jdx) 
                triangle[idx][jdx] += min(triangle[idx+1][jdx], triangle[idx+1][jdx+1]);
        return triangle[0][0];
    }
int main(){
    int t;
    cin>>t;
    while(t--){
        help_yourself()
    }
}
