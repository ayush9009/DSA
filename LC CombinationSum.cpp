class Solution {
public:

//BHT SUNDAR QUESTION DRY RUN MUST HAI,
//KHUD JAB QUESTION PADHOGEY PADHTE PADHTE PATAL LAG JAGA IT'S BACKTRACKING
void helper(vector<int>&v,vector<vector<int>>&ans,vector<int>&candidates,int target,int idx){
    if(target==0){
        ans.push_back(v);
        return ;
    }
    if(target<0)return ;
    for(int i=idx;i<candidates.size();i++){
        if(candidates[i]<=target){
            v.push_back(candidates[i]);
            helper(v,ans,candidates,target-candidates[i],i);   // phir se i kuki chosen elemnt multiple times aa sake
            v.pop_back();
        }
        else{
            break;
        }
    }
    return;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        helper(v,ans,candidates,target,0);
        return ans;
    }
};



  // void helper(vector<vector<int>>&ans,vector<int>v,vector<int>&candidates,int target,int idx){
    //     if(target==0) {
    //         ans.push_back(v);
    //         return ;
    //     }
    //     if(target<0) return;
    //     for(int i=idx;i<candidates.size();i++){
    //         if(candidates[i]<=target){
    //             v.push_back(candidates[i]);
    //             helper(ans,v,candidates,target-candidates[i],i);
    //             v.pop_back();
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     return ;
    // }
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     vector<vector<int>>ans;
    //     vector<int>v;
    //    sort(candidates.begin(),candidates.end());
    //     helper(ans,v,candidates,target,0);
    //     return ans;
    // }
























