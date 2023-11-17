/*
Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
  public:
  
    Node* last;
    //Function to convert binary tree into circular doubly linked list.
    void solve(Node* root,Node* &head, Node* &prev, int &flag)
    {
        if(!root)
            return;
        
        solve(root->left,head,prev,flag);
        
        if(!flag)
        {
            flag = 1;
            head = root;
            prev = root;
            
        }
        else
        {
            prev->right = root;
            prev ->right->left = prev;
            last = root;
            prev = prev->right;
        }
        
        solve(root->right,head,prev,flag);
    }
    
    Node* bTreeToCList(Node* root)
    {
        // Base case
        Node* head = NULL;
        Node* prev = NULL;
        int flag = 0;
        solve(root,head,prev,flag);
        head->left = last;
        last->right = head;
        return head;
    }
};
