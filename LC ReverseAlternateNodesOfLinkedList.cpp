class Solution
{
    public:
    Node* reverse(Node* head){
        Node* prev = NULL, *curr = head;
        while(curr){
            Node* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    void rearrange(struct Node *head)
    {
        // no need to do anything if there are only one or two nodes in the given linked list
        if(!(head -> next) || !(head -> next -> next)) return;
        
        Node* prev = head, *curr = head -> next, *temp = head -> next;
        
        // making two different linked lists for odd and even positions
        while(prev -> next != NULL and curr -> next != NULL){
            prev -> next = curr -> next;
            if(prev -> next) prev = prev -> next;
            curr -> next = prev -> next;
            if(curr -> next) curr = curr -> next;
        }


        // reversing the linked list with an even position (1-based indexing)
        Node* x = reverse(temp);
        
        // connecting the last node of the odd-positioned linked list with the new head of the reversed linked list 
        prev -> next = x;
    }
};
