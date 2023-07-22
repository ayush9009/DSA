class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
       if(head->next==NULL)return head;
     struct Node *prev=head,*curr=head->next;
     set<int> s;
     s.insert(head->data);
     while(curr!=NULL){
         if(s.find(curr->data)!=s.end()){
         while(curr!=NULL && s.find(curr->data)!=s.end()){
             curr=curr->next;
         }
         prev->next=curr;
        }
        if(curr!=NULL)
        s.insert(curr->data);
        prev=curr;
        if(curr!=NULL)
        curr=curr->next;
     }
     return head;

    }
};
