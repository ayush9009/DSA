class Solution {
public:
    
    void helper(vector<vector<int>>&ans,vector<int>&res,int k,int n,int indx){
        if(res.size()==k){
            ans.push_back(res);
            return;
        }
        for(int i=indx;i<=n;i++){
            res.push_back(i);
            helper(ans,res,k,n,i+1);
            res.pop_back();//backtrack
        }
    }
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>>ans;
       vector<int>res;
       helper(ans,res,k,n,1);
       return ans;
    }
};
