class Solution{

  public:
    vector<int>helper(int sum,int n,int arr[]){
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)dp[i][j]=false;
                if(j==0)dp[i][j]=true;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        vector<int>v;
        for(int j=0;j<=sum;j++){
            if(dp[n][j]==true)v.push_back(j);  //[n][j] kuki in last row humara result hoga
        }
        return v;
    }
	int minDifference(int arr[], int n)  { 
	   // s2-s1=(min)  
	   // if we know s1 to hume s2 bhi miljaga i.2 range-s1
	   // (range-s1)-s1=(min)=>means (range-2s1)=minimum
	   // s1,s2 we know abs(s2-s1) =minimum karna to s1 should be smaller s1 nikalna ,
	   // to range kya 0,sigma(arr[i])  to hum ye check kar le  0,sum tak kon kon se ellement hai jinka sum,
	   // ya kahe vo as a element ya unka sum present ho arr,vo s1 mai ayenge
	   // to yani agr number =1 aur arr mai check karna kya koi sum poissible to yani subset sum vala question
	   // bn gya,to yaha se hume vector mil jaga jisme store hoga true,false measn kon kon element possible h
	   // uske bad min(range-2s1) humara answer hoga 
	    sort(arr,arr+n);
	    int sum=0;
	    for(int i=0;i<n;i++)sum+=arr[i];
	    vector<int>result=helper(sum,n,arr);
	    int res=INT_MAX;
	    for(int i=0;i<result.size();i++){
	        res=min(res,abs(sum-2*result[i]));   //range -2s1
	    }
	    return res;
	} 
};
