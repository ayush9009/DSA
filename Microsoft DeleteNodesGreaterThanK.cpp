class Solution{
  public:
    /*The function should return the root of the modified tree*/
    Node* helper(Node* root,int k){
         if (root == NULL)
            return NULL;

        root->left = helper(root->left, k);
        root->right = helper(root->right, k);

        if (root->data >= k) {
            Node* newRoot = root->left;  // Use root->left as the new root
            // root==NULL;
            delete(root);
            return newRoot;
        }

        return root;
    }
    Node* deleteNode(Node* root, int k)
    {
        //Your code herereturn
        return helper(root,k);
        
    }
};
