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
    void traverse(ListNode **r,ListNode *p)
    {
        if(p!=NULL)
        {
            p->next=(*r);
            (*r)=p;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *l=NULL;
        vector<int>result;
        for(auto i:lists)
        {
            ListNode *j=i;
            while(j!=NULL)
            {
                result.push_back(j->val);
                j=j->next;
            }
        }
        sort(result.begin(),result.end());
        ListNode *r=NULL;
        for(int i=result.size()-1;i>=0;i--)
        {
            ListNode *p=new ListNode(result[i]);
            traverse(&r,p);
        }
        return r;
    }
};
