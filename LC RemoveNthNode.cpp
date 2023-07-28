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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //  ListNode* temp=head;
        // ListNode* prev;
        // int len=0;
        // while(temp)
        // {
        //     temp=temp->next;
        //     len++;
        // }
        // temp=head;
        // int s;
        // s=len-n;
        // if(len==1)
        // {
        //     delete(head);
        //     return NULL;
        // }
        // while(s--)
        // {
        //     prev=temp;
        //     temp=temp->next;
        // }
        // if(temp==head)
        // {
        //     head=head->next;
        //     return(head);
        // }
        // if(temp->next==NULL)
        // {
        //     prev->next=NULL;
        //     delete(temp);
        // }
        // else{
        //     prev->next=temp->next;
        //     delete(temp);
        // }
        // return head;





      //optimised approach

    //   example se smjo
    //   suppose 1 2 3 4 5 n=2
    //   0 1 2 3 4 5
    //   fast,slow points to 0
    //   after first loop fast points to 2 
    //   after second loop slow points to 3 and fast points to null
    //   so we do slow->next=slow->next->next that's how we delete node
    //then we return start->next that it's pointer which pounts to 1 (12345)
      ListNode* start=new ListNode(0);
      start->next=head;
      ListNode* fast=start;
      ListNode* slow=start;
      for(int i=1;i<=n;i++){
          fast=fast->next;
      }
      while(fast->next!=NULL){
          fast=fast->next;
          slow=slow->next;
      }
      slow->next=slow->next->next;
      return start->next;
    }
};
