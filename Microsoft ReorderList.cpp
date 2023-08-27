class Solution{ 
public:
    void reorderList(Node* head) {
        // Your code here
       int count =0,right=0,left=1;
       
       unordered_map<int,Node*>mp;
       Node* temp=head;
       while(temp!=NULL){
           mp[++count]=temp;  //mp[1]=node(1)
           temp=temp->next;
       }
       Node* cur=NULL;
       head=mp[left];
       right=count;
       while(left<=right){
           mp[left]->next=mp[right];
           if(cur==NULL){
               cur=mp[right];
           }else{
               cur->next=mp[left];
               cur=mp[right];
           }
           left++;
           right--;
       }
       
       cur->next=NULL;
        
    }
};
