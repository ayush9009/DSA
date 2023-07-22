class Solution {
  public:
    int sumSubarrayMins(int n, vector<int> &a) {
        // code here
        //   int n=a.size();
        stack<int>s1,s2;
        vector<int>nextSmaller(n),prevSmaller(n);
        for(int i=0;i<n;i++){
            nextSmaller[i]=n-i-1; //suppose next smaller ha  ni  to 
            // suppose 2 9 7 8 3 4 6
            // to 3 nextsmaller not exits 
            // 7-4-1=2 i.e (4,6) are the elements which r greaterthanpresent in rightof3
            prevSmaller[i]=i;
            //suppose 9 7 8 3 4 6 1 to 3 prev not exist so elemetns=i i.e 3(3 index=3)
        }
        for(int i=0;i<n;i++){
            while(!s1.empty() && a[s1.top()]>a[i]){
                nextSmaller[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && a[s2.top()]>=a[i]){
                prevSmaller[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        //nextSmaller[i] means no elements greater than i in right side
        //prevSmaller[i] means no elements greater than i in left side
        long long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            // cout<<"I am"<<a[i] <<"and my="<< prevSmaller[i]<<", "<<nextSmaller[i];
            ans+=(a[i]*(prevSmaller[i]+1) * (nextSmaller[i]+1));
            // cout<<endl<<(a[i]*(prevSmaller[i]+1) * (nextSmaller[i]+1))<<endl;
            ans=ans%mod;
        }
        return ans;
    }
};
