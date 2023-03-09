/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // ListNode *slow=head;
        // ListNode *fast=head;
        // bool cycleFound=false;
        // while(fast&&fast->next){
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     if(slow==fast){
        //         cycleFound=true;
        //         break;
        //     }
        // }
        // if(!cycleFound)
        //     return NULL;
        //     fast=head;
        //     while(slow!=fast){
        //         slow=slow->next;
        //         fast=fast->next;
        //     }
        // return slow;
    //     if(head==NULL || head->next==NULL) 
    //         return NULL;
    //     ListNode *slow=head;
    //     ListNode *fast=head;
    //    while(fast->next&&fast->next->next){
    //        slow=slow->next;
    //        fast=fast->next->next;
    //        if(slow==fast){
    //            while(slow!=head){
    //                slow=slow->next;
    //                head=head->next;
    //            }
    //             // cout<<head->val;
    //            return head;
              
    //        }
    //    }
    //     return NULL;
    if(head==NULL && head->next==NULL)return NULL;
    ListNode *slow=head;
    ListNode *fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            while(slow!=head){
                slow=slow->next;
                head=head->next;
            }
             return head;
        }
       
    }
    return NULL;
    }
};
