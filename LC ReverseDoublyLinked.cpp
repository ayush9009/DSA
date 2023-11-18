class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
       if(head==NULL || head->next==NULL)return head;
        Node* cur=head;
        Node* temp=NULL;
        while(cur!=NULL){
            temp=cur->prev;
            cur->prev=cur->next;
            cur->next=temp;
            cur=cur->prev;
        }
        if(temp!=NULL){
            head=temp->prev; //head=4->prev head=5
        }
        // cout<<temp->data;
        // Node* t=NULL;
        return head;
        
    }
};
