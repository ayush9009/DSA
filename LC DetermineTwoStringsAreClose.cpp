class Solution {
public:
    
//     BAHATREEEN QUESTION
    bool closeStrings(string x, string y) {
        if(x==y)return true;
        int n=x.size(),m=y.size();
        if(n!=m)return false;
        vector<int>v1(26,0),v2(26,0);
        for(int i=0;i<n;i++){
            v1[x[i]-'a']++;
            v2[y[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(v1[i]==0 && v2[i]!=0  ||  v1[i]!=0 && v2[i]==0)    //jaise ek mai 'e' hai dusre mai nhi to ek mai not equtal to zero hogi ek mai equal to //zero hve gi
                return false;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2;
    }
};
