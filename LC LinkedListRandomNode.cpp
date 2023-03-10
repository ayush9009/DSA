class Solution {
    
    vector<int>result;
public:
    Solution(ListNode* head) {
        ListNode* cur=head;
        while(cur!=NULL){
            result.push_back(cur->val);
            cur=cur->next;
        }
       
    }
    
    int getRandom() {
        int randomIndex=rand()/(RAND_MAX+1.0)*result.size();
        return result[randomIndex];
        
    }
};
