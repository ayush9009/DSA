class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1==NULL && r2==NULL)return true;
       
        if((r1==NULL || r2==NULL) || r1->data!=r2->data )return false;
      
        auto l=isIdentical(r1->left,r2->left);
        auto r=isIdentical(r1->right,r2->right);
        
        return l&&r;
        
       
    }
};
