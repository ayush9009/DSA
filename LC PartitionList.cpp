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
    void traverse(ListNode **r,ListNode *p){
        if(p!=NULL){
            p->next=(*r);
            (*r)=p;
        }
    }
    ListNode* partition(ListNode* head, int x) {
        vector<int>result;
        vector<int>ans;
        ListNode *curr=head;
        while(curr!=NULL){
            result.push_back(curr->val);
            curr=curr->next;
        }
        for(int i=0;i<result.size();i++){
            if(result[i]<x)
                ans.push_back(result[i]);
        }
        for(int i=0;i<result.size();i++){
            if(result[i]>=x)
                ans.push_back(result[i]);
        }
        ListNode *r=NULL;
        for(int i=ans.size()-1;i>=0;i--){
            ListNode *p=new ListNode(ans[i]);
            traverse(&r,p);
        }
        return r;
    }
};
