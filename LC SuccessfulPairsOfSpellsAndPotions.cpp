class Solution {
public:
    int helper(int &x,vector<int>&potions,long long &success){
        int n=potions.size();
         int low=0,high=n-1;
        int ind=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long t = (long long)x * potions[mid];
            if(t >= success){
                ind=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
      return (n-ind);
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>result;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            result.push_back(helper(spells[i],potions,success));
        }
        return result;
    }
};
