class Solution {
  public:
    void helper(vector<vector<int>>&ans,vector<int>&arr,int index){
        if(index==arr.size()){
            ans.push_back(arr);
            return ;
        }
        unordered_set<int>st;
        for(int i=index;i<arr.size();i++){
            if(st.find(arr[i])!=st.end())continue;  //so that we only unique permutaitons
            st.insert(arr[i]); 
            swap(arr[index],arr[i]);
            helper(ans,arr,index+1);
            swap(arr[index],arr[i]);
        }
      
    }
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        
        vector<vector<int>>ans;
        helper(ans,arr,0);
        sort(ans.begin(),ans.end());
        return ans;
       
    }
};
