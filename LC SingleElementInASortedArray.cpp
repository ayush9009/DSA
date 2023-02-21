class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // return ans;
        // map<int,int>mp;
        // for(int i=0;i<vec.size();i++){
        //     mp[vec[i]]++;
        // }
        // for(auto it:mp){
        //     if(it.second==1)
        //         return it.first;            it is faster than 30%
        // }
        // return 1;
        // int res=0;
        // for(int i=0;i<nums.size();i++){
        //     res=res^nums[i];
        // }
        // return res;
        int n=nums.size()-1;
        int l=0;
        int r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1])               //it is faster than 16%
                    l=mid+2;
                else
                    r=mid;
            }
            else if(mid%2==1){
                if(nums[mid]==nums[mid-1])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return nums[l];
    }
};
