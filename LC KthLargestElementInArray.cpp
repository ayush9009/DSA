class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         int c=0,l;
//         for(int i=n-1;i>=0;i--){
//             c++;
//             if(c==k){
//                 l=nums[i];
//                 break;
//             }
            
//         }
//         return l;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();       //tc->nlogk
    }
};
