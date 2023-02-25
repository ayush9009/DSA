#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string rev=s;
        reverse(rev.begin(),rev.end());
        cout<<"I AM A PALINDROMIC STRING"<<(rev==s)<<endl;
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                break;
            }
        }
        while(i<j){
            if(s[i]!=s[j]){
                s[i]=s[j];
                i++;
                j--;
            }
            else{
                break;
            }
        }
        rev=s;
        reverse(rev.begin(),rev.end());
        cout<<"I am still a palindromic string"<<(rev==s)<<endl;
    }
    return 0;
}
