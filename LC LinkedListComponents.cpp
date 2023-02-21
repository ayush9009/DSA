/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int cnt=1,streak=0;
        ListNode *cur=head;
        unordered_map<int,bool>mp;
        for(auto it:nums){
            mp[it]=true;
        }
        while(cur!=NULL){
            if(mp[cur->val]==true)streak++;
            else{
                if(streak>0){
                    cnt++;
                }
                streak=0;
            }
            cur=cur->next;
        }
        if(streak==0)cnt--;
        return cnt;


    }
};
