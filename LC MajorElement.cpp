class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     //    vector<int>result;
     // int n=nums.size();
     //    int  m=n/3;
     //   for(int i=0;i<n;i++)
     //   {
     //       int c=0;
     //       for(int j=i;j<n;j++)
     //       {
     //           if(nums[i]==nums[j])
     //               c++;
     //       }
     //       if(c>m)
     //           result.push_back(nums[i]);
     //   }
     //    return result;
        // vector<int>result;
        // int m=n/3;
        // for(int i=0;i<n;i++)
        // {
        //     int freq=count()
        // }
        // int mx=-1,c;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            // int freq=count(nums.begin(),nums.end(),nums[i]);
            // if(freq>(n/3))
            //     s.insert(nums[i]);
            mp[nums[i]]++;
        }
         vector<int>result;
        for(auto it:mp){
            if(it.second>(n/3))
                result.push_back(it.first);
        }
        // vector<int>result;
        // for(auto it:s){
        //     result.push_back(it);
        // }
        return result;
    }
};
