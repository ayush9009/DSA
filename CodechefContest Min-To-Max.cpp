#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t
	while(t--){
	    int n
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    int mx=INT_MAX;
	    for(int i=0;i<n;i++){
	        if(mx>a[i])mx=a[i];
	    }
	    int cnt=0;
	    for(int i=0;i<n;i++){
	        if(a[i]==mx)cnt++;
	    }
	    cout<<n-cnt<<endl;
	}
	return 0;
}
