class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node *p1=head1, *p2=head2;
        Node *head=NULL, *tail=NULL;
        
        while(p1 && p2)
            if(p1->data > p2->data)
                // nodes dont match
                // moving to next node in list with smaller node
                p2 = p2->next;
            
            else if(p2->data > p1->data)
                // nodes dont match
                // moving to next node in list with smaller node
                p1 = p1->next;
            
            else
            {
                // nodes match
                
                if(head==NULL)
                    head = tail = new Node(p1->data);
                    // creating new head for intersection list
                else
                {
                    // appending new node at the end
                    tail->next = new Node(p1->data);
                    tail = tail->next;
                }
                p1 = p1->next;
                p2 = p2->next;
                // moving to next nodes in both lists
            }
        
        return head;
    }
};
