class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // int n=nums.size();
        // vector<int>result;
        // for(auto it:nums)mp[it]++;
        // for(auto it:mp){
        //     if(it.second > n/3){
        //         result.push_back(it.first);
        //     }
        // }
        // return result;

        
        // IMPNote:suppose n=9 
        // we have to find elements that occcur more than (9/3) i.e 3 means the elemen twhose  count kam se kam ki bt kare to kam se kam uski count 4 , 4+4+4=12>9 so only two elements are our answer
        //  IMPNote:suppose n=19 
        // we have to find elements that occcur more than (19/3) i.e 6 means the elemen twhose  count kam se kam ki bt kare to kam se kam uski count 7 , 7+7+7=21>7 7+7=14<19  so only two elements are our answer

        // conclusion is that we have only 2 elements in our answer

        //here we use moore's voting algo(use thoda modify karke karenge)
        // moore's algo for element occuring more than n/2 times
        // int cnt=0,elem=0;
        // for(int i=0;i<n;i++){
        //     if(cnt==0){
        //         cnt=1;
        //         elem=nums[i];
        //     }else if(elem==nums[i])cnt++;
        //     else cnt--;
        // }
        // cnt=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==elem)cnt++;
        // }
        // (cnt>(n/2))?elem:-1;

         // moore's algo for element occuring more than n/3 times
        int n=nums.size();
        int cnt1=0,elem1=0,cnt2=0,elem2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0 && elem2!=nums[i]){ //kuki elem1 ek element ka dhyn rakega aur elem2 dusre ka dono elem1 and elem2 not equal hone chaiye 
                cnt1=1;
                elem1=nums[i];
            }
            else if(cnt2==0 && elem1!=nums[i]){
                cnt2=1;
                elem2=nums[i];
            }
            else if(elem1==nums[i])cnt1++;
            else if(elem2==nums[i])cnt2++;
            else {
                cnt1--;
                cnt2--;
            }

        }
        cnt1=0,cnt2=0;
        vector<int>result;
        for(int i=0;i<n;i++){
            if(nums[i]==elem1)cnt1++;
            else if(nums[i]==elem2)cnt2++;
        }
        if(cnt1>(n/3))result.push_back(elem1);
        if(cnt2>(n/3))result.push_back(elem2);
        return result;
    }
};
