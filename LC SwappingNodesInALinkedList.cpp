**
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
    ListNode* swapNodes(ListNode* head, int k) {

        // ListNode *cur=head;
        // int k1=k,k2=0;
        // int temp,temp2,cnt=0;
        // while(cur!=NULL){
        //     cnt++;
        //     cur=cur->next;
        // }
        // if(cnt==1)return head;
        // cur=head;
        // while(cur!=NULL){
        //         k1--;
        //         if(k1==0)temp=cur->val;
        //         cur=cur->next;
        // }
        // cout<<cnt<<endl;
        // cout<<temp<<endl;
        // cur=head;
        // while(cur!=NULL){
        //     k2++;
        //     if(cnt-k2==k){
        //         break;
        //     }
        //     cur=cur->next;
        // }
        // if(cur!=NULL)temp2=cur->next->val;
        // cout<<temp2;
        // k1=k,cur=head;
        // while(cur!=NULL){
        //     k1--;
        //     if(k1==0){
        //          cur->val=temp2;
        //          break;
        //     }
        //     cur=cur->next;
        // }
        //  cur=head,k2=0;
        // while(cur!=NULL){
        //     k2++;
        //     if(cnt-k2==k && (cur!=NULL)){
        //          cur->next->val=temp;
        //         break;
        //     }
        //     cur=cur->next;
        // }
        // return head;
          int len=0;
        ListNode* node = head;
        ListNode* temp1=NULL, temp2=NULL;

        while(node){
            len++;
            if(k == len)
                temp1 = node;
            node = node->next;
        }
        k = len-k;
        node = head;
        while(k--)
            node = node->next;

        int x = temp1->val;
        temp1->val = node->val;
        node->val = x;
        return head;


    }
};
