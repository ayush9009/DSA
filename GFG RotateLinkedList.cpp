class Solution
{
    public:
    void traverse(Node**r,Node*p){
       p->next=(*r);
       (*r)=p;
    }
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // // Your code here
        // vector<int>result;
        // Node* cur=head;
        // while(cur!=NULL){
        //     result.push_back(cur->data);
        //     cur=cur->next;
        // }
        
        // while(k--){
        //      int temp=result[0];
        //      int n=result.size();
        //      for(int i=0;i+1<n;i++){
        //         result[i]=result[i+1];
        //      }
        //     //  for(auto it:result)cout<<it<<" ";
        //      result[n-1]=temp;
        // }
        // Node*r=NULL;
        // for(int i=result.size()-1;i>=0;i--){
        //     Node*p=new Node(result[i]);
        //     traverse(&r,p);
        // }
        // return r;
        //optimised apporach
        if(head==NULL || k==0)return head;
        Node* temp=head;
        Node* last=head;
        while(last->next!=NULL){
            last=last->next;
        }
        while(k){
            head=head->next;
            temp->next=NULL;
            last->next=temp;
            last=temp;  //last node kai next mai to null hi hoa
            temp=head;
            k--;
        }
        return head;
    }
};
