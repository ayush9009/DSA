class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>result1;
        //  vector<int>result2;
        // vector<vector<int>>ans;
        // vector<int>num1;
        // vector<int>num2;
        // int flag;
        // for(int i=0;i<nums1.size();i++){
        //     int freq=count(nums1.begin(),nums1.end(),nums1[i]);
        //     if(freq==1)
        //         num1.push_back(nums1[i]);
        // }
        // for(int i=0;i<nums2.size();i++){
        //     int freq=count(nums2.begin(),nums2.end(),nums2[i]);
        //     if(freq==1)
        //         num2.push_back(nums2[i]);
        // }
        // for(int i=0;i<num1.size();i++)
        // {
        //     flag=0;
        //     for(int j=0;j<num1.size();j++){
        //         if(num1[i]==num2[j]){
        //             flag=1;
        //             break;
        //         }
        //     }
        //     if(flag!=1)
        //         result1.push_back(num1[i]);
        // }
        // ans.push_back(result1);
        //  for(int i=0;i<num2.size();i++)
        // {
        //     flag=0;
        //     for(int j=0;j<num1.size();j++){
        //         if(num2[i]==num1[j]){
        //             flag=1;
        //             break;
        //         }
        //     }
        //     if(flag!=1)
        //         result2.push_back(num2[i]);
        // }
        // ans.push_back(result2);
        // return ans;
        map<int,int>m1;
        map<int,int>m2;
        for(auto x:nums1)
            m1[x]++;
        for(auto x:nums2)
            m2[x]++;
        vector<vector<int>>ans;
        vector<int>result;
        for(auto x:m1){
            if(m2.find(x.first)==m2.end())
                result.push_back(x.first);
        }
        ans.push_back(result);
        result.clear();
        for(auto x:m2){
            if(m1.find(x.first)==m1.end())
                result.push_back(x.first);
        }
        ans.push_back(result);
        result.clear();
        return ans;
    }
};
