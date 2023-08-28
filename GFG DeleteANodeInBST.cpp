//VVIP QUESTION ON BST

Node *deleteNode(Node *root, int x) {
     if(root==NULL)return root;
     
     if(root->data > x){
         root->left=deleteNode(root->left,x);
         return root;
     }
     
     if(root->data < x){
         root->right=deleteNode(root->right,x);
         return root;
     }
     
    //  see if root->data==x,
    //  there are following conditions:
    //  if root->left==NULL and root->right==NULL so we simply delete root
    //  but if root have one child then what we do,how to delete 
    //  see if root have both child then how to delete,below we handle all these cases 
     else {  
         if(root->left==NULL){
             Node* temp=root->right;
             delete root;
             return temp;
         }
         else if(root->right==NULL){
             Node* temp=root->left;
             delete(root);
             return temp;
         }else{
             Node* sucParent=root;
             Node* suc=root->right;
             while(suc->left!=NULL){
                 sucParent=suc;
                 suc=suc->left;
             }
             if(sucParent!=root)sucParent->left=suc->right;//kukisuc->lefttonullhaiisliyesuc->rightsejoddia
             else sucParent->right=suc->right;//ye case meri smj bhi ni aya 
             
             root->data=suc->data;
             delete(suc);
         }
         
         return root;
     }
}
