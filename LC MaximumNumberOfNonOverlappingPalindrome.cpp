class Solution {
public:
    bool check(string s){
        
        string m=s;
        // string k=m;
        reverse(m.begin(),m.end());
        return m==s;
    }
    int maxPalindromes(string s, int k) {
        // if(k==1)return s.size();
        // unordered_map<int,int>mp;
        // int n=s.size();
        // vector<string>result;
        // for(int len=k;len<n;len++){
        //     for(int i=0;i<=n-len;i++){
        //         int j=i+len-1;
        //         if(s[i]==s[j]){
                    
        //             int flag=1;
        //             for(int m=i;m<=j;m++){
        //                if(mp.find(m)!=mp.end()){flag=0; break;}
        //             }
        //             if(flag==1)
        //             {  
        //                 string z=s.substr(i,len);
        //                 if(check(z)){
        //                   result.push_back(s.substr(i,len));
        //                   for(int r=i;r<=j;r++)mp[r]++;
        //                 }
        //             }
        //             // mp[j]++;
        //         }
        //     }
        // }
        // int cnt=0;
        // for(auto it:result){
        //     // if(check(it)){
        //         cnt++;
        //         cout<<it<<" ";
        //     // }
        // }

        // return cnt;
        int n=s.size();
        int cnt=0;
        int i=0,j=0,t=0;
        while(i<n-k+1){
            j=i;
            t=i+1;
            string str="";
            while(j<n){
                str+=s[j];
                if(str.size()>k+1)break;
                if(str.size()>=k){
                    if(check(str)){
                        cnt++;
                        t=j+1;
                        str="";
                    }
                }
                j++;
            }
            i=t; //taki overlappig na ho,t ka use hi sirf overlapping ko rokne kai liye
        }
        return cnt;
    }
};
