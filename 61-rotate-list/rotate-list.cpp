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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;
        ListNode* cur=head;
        int len=0;
        while(cur!=NULL){
            len++;
            cur=cur->next;
        }
        k=k%len; //impo thing
        cur=head;
        ListNode* lastNode=head;
        for(int i=0;i<k;i++){
            ListNode* hd=cur;
            while(cur!=NULL && cur->next!=NULL && cur->next->next!=NULL){
                cur=cur->next;
            }
           
            if(cur!=NULL && cur->next!=NULL)
              lastNode = cur->next;
            if(cur!=NULL)cur->next=NULL;
            if(lastNode!=NULL)lastNode->next=hd;
            cur=lastNode;
        }

        return lastNode;
    }
};