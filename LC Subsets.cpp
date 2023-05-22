class Solution {
public:
    // vector<vector<int>>sets;
    // void generate(vector<int>&subset,int i,vector<int>&nums)
    // {
    //     if(i==nums.size())
    //     {
    //         sets.push_back(subset);
    //         return;
    //     }
    //     generate(subset,i+1,nums);
    //     subset.push_back(nums[i]);
    //     generate(subset,i+1,nums);
    //     subset.pop_back();
    // }
    void helper(vector<int>&res,vector<vector<int>>&ans,int indx,vector<int>& nums){
        if(indx==nums.size()){
            ans.push_back(res);
            return;
        }
        helper(res,ans,indx+1,nums);
        res.push_back(nums[indx]);
        helper(res,ans,indx+1,nums);
        res.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<int>subset;
    //    generate(subset,0,nums);
    //     return sets;
    vector<int>res;
    vector<vector<int>>ans;
    helper(res,ans,0,nums);
    return ans;
    
    }
};
