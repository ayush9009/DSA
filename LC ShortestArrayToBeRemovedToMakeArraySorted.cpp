class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
       int n=arr.size();
       int s=0,e=n-1;
       while(s<n-1 && arr[s]<=arr[s+1])s++;
       if(s==n-1)return 0; //mtlb already increasig hai puri array

       while(e>=s && arr[e]>=arr[e-1])e--;   //why?e>=s kuki stak hi increasing kai bad ni,isliye..
       if(e==0)return n-1;
       int result=min((n-1)-s,e);   //(n-1) kui 0 base indexing use hove na vector m
       
       int i=0,j=e;
       while(i<=s && j<n){
           if(arr[j]>=arr[i]){
               result=min(result,j-i-1);
               i++;
           }else{
               j++;   //agr we get j to uske agey sab greater hi hongey particular ise
           }
       }
       return result;
    }

};
