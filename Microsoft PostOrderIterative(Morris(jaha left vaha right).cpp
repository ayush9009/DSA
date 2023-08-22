class Solution{
    public:
    //same as inorder bas inorder mai jaha left tha ,vaha ab right kar do,aur jaha right h vaha left kardo,
    // print statement same rahenge bas in the end return karna reverse karke
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>result;
        Node* cur=root;
        while(cur!=NULL){
            if(cur->right==NULL){
                result.push_back(cur->data);
                cur=cur->left;
            }else{
                Node* prev=cur->right;
                while(prev->left!=NULL && prev->left!=cur){
                    prev=prev->left;
                }
                if(prev->left==NULL){
                    prev->left=cur;
                    result.push_back(cur->data);
                    cur=cur->right;
                }else{
                    prev->left==NULL;
                    cur=cur->left;
                }
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
