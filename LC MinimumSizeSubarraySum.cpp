class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
                    int n=a.size();
        int sum=0;
        int ans=INT_MAX;
        int i=0,j=0;
        while(j<n)
        {
            sum+=a[j];
            if(sum<target)
                j++;
            else
            {
                while(sum>=target)
                {
                    if(sum>=target)
                     ans=min(ans,j-i+1);
                    sum-=a[i];
                    i++;
                    if(sum>=target)
                     ans=min(ans,j-i+1);
                      
                  
                }
                j++;
            }
            
        }
        return (ans==INT_MAX?0:ans);
    }
};
