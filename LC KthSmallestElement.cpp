class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //in interview first tell sorting apporach then tell ,in worst case it may take
        //Onlogn
// we can optimised it,by using min heap and it takes time complexity O(nlogk)
//  arr={7,5,3,20,15,10}, now agr sorting ki bat kare to 7,5,3 inhe to sortingkarne ki jaroat ni,kuki kth largest chaiye to ye extra kam na karne pade hum lik denge 
//  if(pq.size()>k)pq.pop() to aise karne se sirf jaroat vale elements sort hongey
        // aur inlast pq mai honge  10 15 20 to top par 10 to return pq.top

        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};
