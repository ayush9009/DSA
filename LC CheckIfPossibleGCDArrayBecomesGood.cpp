#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int mn=INT_MIN;
        for(int i=1;i<n;i++){
            mn=min(mn,__gcd(a[i],a[i-1]));
        }
        if(mn<=2)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
