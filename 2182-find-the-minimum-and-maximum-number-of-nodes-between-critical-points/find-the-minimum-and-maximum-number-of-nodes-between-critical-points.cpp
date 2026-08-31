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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>res;
        ListNode* cur=head;
        while(cur!=NULL){
            res.push_back(cur->val);
            cur=cur->next;
        }
        map<int,int>mp;
        for(int i=1;i+1<res.size();i++){
            if(res[i]>res[i-1] && res[i]>res[i+1]){
                mp[i+1]=res[i];
            }
            if(res[i]<res[i-1] && res[i]<res[i+1]){
                mp[i+1]=res[i];
            }
        }
        
        if(mp.size() < 2) {
            return {-1, -1};
        }
        
        vector<int> criticalPoints;
        for(auto it: mp){
            criticalPoints.push_back(it.first);
        }
        
        int mini = INT_MAX;
        int maxi = criticalPoints.back() - criticalPoints.front();
        
        for(int i = 1; i < criticalPoints.size(); i++) {
            mini = min(mini, criticalPoints[i] - criticalPoints[i - 1]);
        }
        
        return {mini, maxi};
    }
};
