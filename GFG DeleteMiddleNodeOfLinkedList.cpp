Node* deleteMid(Node* head)
{
    // Your Code Here
    if(head==NULL)return NULL;
    if(head->next==NULL)return NULL;
    Node* cur=head;
    int cnt=0;
    while(cur!=NULL){
        cnt++;
        cur=cur->next;
    }
    cnt=cnt/2;
    int x=0;
    cur=head;
    while(cur!=NULL && x!=cnt-1){
        cur=cur->next;
        x++;
    }
    cur->next=cur->next->next;
    return head;
}
