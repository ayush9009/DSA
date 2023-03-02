class Solution {
public:

    int compress(vector<char>& nums){
        int n = nums.size();
        int count=1;
        int j=0;
        int i=0;
        for( ; i<n; i++){
            if(i<n-1 && nums[i] == nums[i+1]){
                count++;
                continue;
            }
            nums[j] = nums[i];
            j++;
            if(count > 1){
                string str = to_string(count);
                for(auto it : str){
                    nums[j++] = it;
                }
                count = 1;
            }   
        }
        nums.resize(j);
        return nums.size();
    }
};
