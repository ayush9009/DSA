class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for (int i = 0; i < n; i++) {
            // i>0 kkuki i=0 vala to already cosnider karliye na
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // toavoid duplicates
            for (int j = i + 1; j < n; j++) {
                // //cur,prev kai equal to ignore nums[j]==nums[j-1] check 
                // to karo par kab , jab j!=i+1 means first index ko move kar 
                // do usme koi dikt ni, par agr i=0, j=2 to aap nums[1]==nums[2]
                // agr equal to agey move forward toavaoud uplicates
                if (nums[j] == nums[j - 1] && j != i + 1)
                    continue;

                int k = j + 1, l = n - 1;
                while (k < l) {
                    //sorted h to binary saerch ya normal prointer app lagado
                    long long int sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);

                        k++;l--;
                        while(k<l && nums[k]==nums[k-1])k++;
                        while(k<l && nums[l]==nums[l+1])l--;
                    }else if(sum < target){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};