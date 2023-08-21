class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    
    // VVIP QUESTION
    
    
    bool isIdentical(Node* root, Node* r){
        
        if(root==NULL && r==NULL)return true;
        if(root==NULL || r==NULL)return false;
        
        return (root->data==r->data && isIdentical(root->left,r->left) && isIdentical(root->right,r->right));
    }
    bool isSubTree(Node* root, Node* r) 
    {
        // Your code here
        if(root==NULL)return false;
        if(r==NULL)return true;
        
        if(isIdentical(root,r))return true;
        
        return (isSubTree(root->left,r) || isSubTree(root->right,r));
        
        
    }
};
