class Solution {
public:
    //BADIYA QUESTION
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       long  res=0;
        int n=nums.size();
        bool maxFound=false,minFound=false;
        int start=0,maxStart=0,minStart=0;
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK){
                maxFound=false;
                minFound=false;
                start=i+1;
            }
            if(nums[i]==minK){
                minFound=true;
                minStart=i;
            }
            if(nums[i]==maxK){
                maxFound=true;
                maxStart=i;
            }
            if(minFound && maxFound){
                res+=(min(minStart,maxStart)-start+1);  //minimum isllye le rai kuki array ki start
                //array ki starting minimum se bhi ho aur max sebhi yaha isluye minimumindex chaiye
                //kuki array sort ni hai isliye
            }
        }
        return res;
    }
};
