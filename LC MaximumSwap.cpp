class Solution {
public:
    int maximumSwap(int num) {
        // long long int temp =num;
        // vector<int>result;
        // int i=0;
        // while(temp>0){
        //     result.push_back(temp%10);
        //     // cout<<result[i++]<<" "<<endl;
        //     temp/=10;
        // }
        // reverse(result.begin(),result.end());
        // // int i1,i2;
        // // int mx=INT_MIN,mn=INT_MAX;
        // // for(int i=0;i<result.size();i++){
        // //     if(mx<result[i]){mx=result[i];i1=i;}
        // //     if(mn>result[i]){mn=result[i];i2=i;}
        // //     cout<<mx<<" "<<mn<<endl;
        // // }
        // // if(i1!=0){
            
        // //     swap(result[i1],result[i2]);
        // //     int nm=result[0];
        // //     cout<<result[i1]<<" "<<result[i2]<<endl;
        // //     for(int i=1;i<result.size();i++){
        // //         nm=nm*10+result[i]%10;
        // //         cout<<nm<<" "<<endl;
        // //     }
        // //     return nm;
        // // }
        // int mn=result[0],idx1,idx2=0,mx=INT_MIN;
        // for(int i=1;i<result.size();i++){
        //     if(result[i]>result[i-1]){
        //         if(mx<result[i]){
        //             mx=result[i];
        //             idx1=i;
        //         }
        //     }
        //     if(result[i]<mn){
        //         mn=result[i];
        //         idx2=i;
        //     }
        // }
        // if(mx!=INT_MIN){
        //     cout<<idx1<<endl;
        //     swap(result[idx1],result[idx2]);
        //     int nm=result[0];
        //     for(int i=1;i<result.size();i++){
        //         nm=nm*10+result[i]%10;
        //         // cout<<nm<<" "<<endl;
        //     }
        //     return nm;
        // }
        // return num;
        string s=to_string(num);
        int n=stoi(s);
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                swap(s[i],s[j]);
                n=max(n,stoi(s));
                swap(s[i],s[j]);
            }
        }
        return n;
    }
};
