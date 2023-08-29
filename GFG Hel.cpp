class Solution {
public:
    
  
    
    int bestClosingTime(string s) {
        int n=s.size();
        int maxi=0;
        int ans=0;
        pair<int,int>cnt={0,0};
        for(int i=0;i<n;i++){
            if(s[i]=='Y'){
                cnt.first++;
                cnt.second=i+1;
            }else{
                cnt.first--;
                cnt.second=i;
            }
            if(cnt.first>maxi){
                ans=cnt.second;
            }
            maxi=max(maxi,cnt.first);
        }
        return ans;
    }
};
