#include <bits/stdc++.h>
#define int long long
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
  
void ruk_ja_bhai(int &tora_bhai,vector<int>&ans_bhai,int &no_elemen2,int &christmas){
        while(tora_bhai >= 1){
            ans_bhai.push_back(min(christmas / tora_bhai, no_elemen2 - 1));
            christmas -= ans_bhai.back() * tora_bhai;
            tora_bhai--;
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
  
void print(vector<int>&ans_bhai,int i){
    cout << ans_bhai[i] + 1 << " ";
}
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}
void helper(int &tora_bhai,int &christmas,int &no_elemen2){
        vector<int> ans_bhai;
        ruk_ja_bhai(tora_bhai,ans_bhai,no_elemen2,christmas);
        for(int i = ans_bhai.size() - 1; i >= 0; i--) print(ans_bhai,i);
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
void read(int &no_elemen,int &no_elemen2,int &no_elemen3){
    cin >> no_elemen >> no_elemen2 >> no_elemen3;
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
void printing(int tora_bhai){
    cout << 1 << " " << tora_bhai << endl;
}
void printArr(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
} 
bool check(int christmas,int tora_bhai){
    return christmas > tora_bhai;
}
 int minimumTotal(vector<vector<int>>& triangle) {
      for(int idx = triangle.size()-2; idx >=0; --idx) 
            for(int jdx = 0; jdx < triangle[idx].size(); ++jdx) 
                triangle[idx][jdx] += min(triangle[idx+1][jdx], triangle[idx+1][jdx+1]);
        return triangle[0][0];
    }
void update(int &christmas,int &tora_bhai){
    christmas -= tora_bhai + 1;
}
 string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();

        // offline query vala concept use huha yaha pr range sum query vala concept ki hum array nikalenge
        // jisme har element ka pta lag jaga ye kitne steps shift hona,vo kaise niklega
        // deko do variables start end ,(start yani begin kaha se hora end yani particular point ki iseyageynijasakte)
        // start kai sath sath end+1 update hota rahega
        // example se smjo
        // dp(n+1,0)=dp{0,0,0,0}
        // query{0,1,0},itmeans start=0 end=1 decrement operation {-1,0,1,0} ab dp[start]=-1 hona to dp[end+1]=1 (yaniulta)
        // query{1,2,1},start=1,end=2 increment operaiton{-1,1,1,-1} dp[start]=1 hora to dp[end]=-1 kar do
        // query{0,2,1},start=0,end=2 incremnt operaion{0,1,1,0}dp[start]=0 dp[end]=0 0 opposite 0

        // ab prefix array tyar hai lakin ab hume prefic sum array chaiye
        // {0,1,1,0}={0,0+1,0+1+1,0+1+1+0}={0,1,2,2}
        // s=abc shifting a by 0 times i.e s=abc
        // s=abc shifting b by 1 times i.e s=acc
        // s=abc shifting c by 2 times i.e s=ace this is the answer

        vector<int>dp(n+1,0);
        for(auto &it:shifts){
            int start=it[0],end=it[1],diret=it[2];
            if(diret==1){
                ++dp[start];
                --dp[end+1];
            }else if(diret==0){
                   --dp[start];
                   ++dp[end+1];
            }
        }
        for(int i=1;i<=n;i++){
            dp[i]+=dp[i-1];   //prefix sum array
        }

        for(int i=0;i<n;i++){
            if(dp[i]<0)dp[i]=(-(abs(dp[i])%26)+26)%26;   //handling negative values(tricky)
            s[i]=(char)('a'+ (s[i]-'a' + dp[i] + 26)%26); //shifting vala scene
        }
        return s;
    }
void update2(int &tora_bhai){
     tora_bhai++;
}
  bool matching_vectors(vector<int>a,vector<int>b){
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
void scene_hogya(int no_elemen3,int no_elemen,int no_elemen2){
    for(int i = 0; i < no_elemen3; i++){
        int christmas;
        cin >> christmas;
        int tora_bhai = 0;
        while(tora_bhai < no_elemen){
            if(check(christmas,tora_bhai)){
                update(christmas,tora_bhai);
            }else{
                break;
            }
           update2(tora_bhai);
        }
        printing(tora_bhai);
        helper(tora_bhai,christmas,no_elemen2);
        cout << endl;
    }
}
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
void help_yourself(){
      int no_elemen, no_elemen2, no_elemen3;
      read(no_elemen,no_elemen2,no_elemen3);
    scene_hogya(no_elemen3,no_elemen,no_elemen2);
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
signed main() {
	// your code goes here
	int t=1;
	while(t--){
	    help_yourself();
	}
	return 0;
}
