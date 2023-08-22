class Solution{
    public:
    vector<int> preOrder(Node* root)
    {
        //code here
         //code here
        vector<int>preorder;
        Node* cur=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                preorder.push_back(cur->data);
                cur=cur->right;
            }else{
                Node *prev=cur->left;
                while(prev->right!=NULL && prev->right!=cur ){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    preorder.push_back(cur->data);
                    prev->right=cur;
                    cur=cur->left;
                }else{
                    prev->right=NULL;
                    
                    cur=cur->right;
                }
            }
        }
        return preorder;
    }
};
