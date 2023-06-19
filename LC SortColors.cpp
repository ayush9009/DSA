class Solution {
public:
    void sortColors(vector<int>& nums) {
        int min;
    for(int i=0;i<nums.size();i++)
    {
        min=nums[i];
        for(int j=i+1;j<nums.size();j++)
        {
            int temp;
                if(min > nums[j])
                {
                    temp=min;
                    min=nums[j];
                    nums[j]=temp;
                }
        }
        nums[i]=min;
    }
    }
};
