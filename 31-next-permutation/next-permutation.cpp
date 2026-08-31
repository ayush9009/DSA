class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        int n=nums.size();
        //first element smaller from right
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }

        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        //smallest element greater than nums[idx]
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }

       //suffix ka order change hogya to vo sahi karne k liye
       //132 next would 213 , 
       //to humne swapp se kar diya, 231 par suffix order get chnage
       //to vohi sahi karo , 3 to 1 reverse kardo, 
       //213 ho jaga, deko ye bht basisc example h
       //aur kuch cases lo khud se solve karo pta lag jaga. 
        reverse(nums.begin()+idx+1,nums.end());


    }
};