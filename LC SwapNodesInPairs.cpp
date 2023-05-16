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
    void singlyList(ListNode **r,ListNode *p)
    {
        p->next=(*r);
        (*r)=p;
    }
    ListNode* swapPairs(ListNode* head) {
      vector<int>result;         //here we dont have to change the values of ,here we have to 
      while(head!=NULL){
             result.push_back(head->val);
             head=head->next;               //sort the nodes,that
       }
        int i=0,temp;
        int n=result.size();
        for(int i=0;(i<n && i+1<n);i+=2){
            swap(result[i],result[i+1]);
        }
        ListNode *r=NULL,p;
        for(int i=n-1;i>=0;i--){
            ListNode *p=new ListNode(result[i]);
            singlyList(&r,p);
        }
        return r;
    }
};
