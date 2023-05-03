#include <bits/stdc++.h>
using namespace std

void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k
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
  
void printing1(){
       cout<<"CHEF"<<endl;
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
void printing2(){
     cout<<"CHEFINA"<<endl;
}
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  

bool check(long long no_elemen,long long no_elemen2){
    return no_elemen==no_elemen2;
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
 
bool check2(long long no_elemen){
    return no_elemen%2;
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
bool check3(long long result){return result==1;}
void printArr(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
bool check4(long long no_elemen){return no_elemen%2==0;}
int maxProfit(vector<int>& prices) {
    //     int mini=prices[0];
    //     int profit=0;
    //     for(int i=0;i<prices.size();i++)
    //     {
    //         mini=min(prices[i],mini);
    //         profit=max(profit,(prices[i]-mini));
    //     }
    // return profit;
        int mini=prices[0],profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            int cost=prices[i]-mini;
            profit=max(cost,profit);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
bool check5(long long no_elemen,long long no_elemen2){return no_elemen+1==no_elemen2;}
bool dfs(vector<vector<int>>& grid,int i,int j){
        if(i+1==grid.size() && j+1==grid[0].size())return true;
        if(i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)return false;
        grid[i][j]=0;
        return dfs(grid,i+1,j)||dfs(grid,i,j+1);
    }
void print1(){
    cout<<"CHEFINA"<<endl;
}
 bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if(dfs(grid,0,0)==false)return true;
        grid[0][0]=1;
        return !dfs(grid,0,0);
    }
void to_do(long long no_elemen,long long no_elemen2){
        if(no_elemen>no_elemen2)cout<<"CHEF"<<endl;
        else cout<<"CHEFINA"<<endl;
}
int ed(int m,int n,string &s1,string &s2){
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            dp[i][0]=i;  //jiase if i<0 tha in 0 indexing mai to 1 indexing mai i==0 to returnj(yani i kuch bhi ho return j karo)
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else 
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])); //insert,delete,replace
            }
        }
        return dp[m][n];
    }
void print2(){
    cout<<"CHEF"<<endl;
}
 int minDistance(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        return ed(m,n,s1,s2);
    }
bool check8(long long no_elemen,long long no_elemen2){
    return no_elemen+1==no_elemen2;
}
 long long distinctNames(vector<string>& ideas) {
        unordered_set<string>s;
        for(auto it:ideas){
            s.insert(it);
        }
         vector<vector<int>> dp(26, vector<int> (26, 0));
        for(int i=0;i<ideas.size();i++){
            string idea=ideas[i];
            char old_idea=idea[0];
            for(char new_idea='a';new_idea<='z';new_idea++){
                idea[0]=new_idea;
                // cout<<idea<<"hahah<<endl";
                if(s.count(idea)==0){
                    dp[old_idea-'a'][new_idea-'a']++;
                    //ab agr dp[c][a],jabki a hai bhi ideas ki kisi string kai shuru mai
                    //to dp[c][a] 
                    //lakin dp[a][c] kabhi ni aneka to dp[a][c]=0,dp[c][a]=1,to inka prod=0
                    // for example coffee donuts doffee conuts dp[c][d]++
                    //aise hi jab donuts ayega to coffee kai liye deka jaga
                    // tab dp[d][c]++;
                    //tabhi ans=dp[c][d]*dp[d][c] kara va
                    // cout<<dp[old_idea-'a'][new_idea-'a']<<" "<<"tora"<<endl;
                }
            }
        }
            long long cnt=0;
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    
                    cnt+=(long long)dp[i][j]*(long long)dp[j][i];
                    cout<<dp[i][j]*dp[j][i]<<endl;
                }
            }
        return cnt;
    }
void tora1(long long no_elemen,long long no_elemen2){
            if(check5(no_elemen,no_elemen2)){
                print1();
            }else print2();
}
int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>graph(n,vector<int>());
        vector<int>indegree(n);
        for(auto &edge:relations){
            int prev=edge[0]-1;
            int next=edge[1]-1; //-1 kuki question mai kahani 1 2 3 aise shuru haiaurhum0sekrenge
            graph[prev].push_back(next);
            indegree[next]++;
        }
        queue<int>q;
        vector<int>dist(n,0);
        for(int u=0;u<n;u++){
            if(indegree[u]==0){
                q.push(u);
                dist[u]=time[u];
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:graph[u]){
                // updatte dist[v] maximum distance of predecessor(that appear just before) nodes
                //if we get he dis[u] of predecrsor nodes then we get for currnt node also
                //because to next course u have to complete prev course
                // thatwhy we use concept of topo sort to complete n courses
                dist[v]=max(dist[v],dist[u]+time[v]); 
                if(--indegree[v]==0)q.push(v);
            }
        }
        return *max_element(dist.begin(),dist.end());

    }
void tora2(long long no_elemen,long long no_elemen2){
            if(check8(no_elemen,no_elemen2))print2();
            else print1();
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
void help_yourself(){
    long long no_elemen,no_elemen2;
    cin>>no_elemen>>no_elemen2;
    if(check(no_elemen,no_elemen2)){
        if(check2(no_elemen))printing1();
        else printing2();
        return;
    }
    long long result=abs(no_elemen-no_elemen2);
    if(check3(result)){
        if(check4(no_elemen)){
            tora1(no_elemen,no_elemen2);
        }else{
            tora2(no_elemen,no_elemen2);
        }
        return;
    }
    else{
        to_do(no_elemen,no_elemen2);
    }
}
  int longestSubarray(vector<int>& nums) {
        int ans=0;
        int cnt_sum=0; //no. of ones
        int cnt_zero=0;
        int i=0;  //starting point for the window
        int n=nums.size();
        for(int j=0;j<n;j++){
            if(nums[j]==1){
                cnt_sum++;
            }else{
                cnt_zero++;
            }
            while(cnt_zero>1){
                cnt_sum=cnt_sum-nums[i];
                if(nums[i]==0)cnt_zero--;
                i++;  //window ab agey badh gi 
            }
            ans=max(ans,cnt_sum);
        }
        if(ans==n)return ans-1;
        return ans;
    }
    // int height(TreeNode* root)
    // {
        // if(root==NULL)
        //     return 0;
        // else
        //     return max(height(root->left),height(root->right))+1;
        
    // }
int main() {
	int t;
	cin>>t;
	while(t--){
	    help_yourself();
	}
	return 0;
}
