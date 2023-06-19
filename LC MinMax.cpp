class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(auto it:nums){
            if(mx<it)mx=it;
        }
         for(auto it:nums){
            if(mn>it)mn=it;
        }
        int x=-1;
        for(auto it:nums){
            if(it!=mx && it!=mn){
                x=it;
                break;
            }
        }
        return x;
    }
};
