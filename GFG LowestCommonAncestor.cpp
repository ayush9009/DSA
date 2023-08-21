
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL)return root;
       if(root->data==n1 || root->data==n2)return root;
       
       Node* lca1=lca(root->left,n1,n2);
       Node* lca2=lca(root->right,n1,n2);  
       
       if(lca1!=NULL && lca2!=NULL)return root;   // example1: lca1=2 lca2=3 lca!=null lca2!=NULL return root(1)
       if(lca1!=NULL)return lca1; //ye case tab hai jab dono ek hi taraf ho yani ya left subtree mai ya right m
       if(lca2!=NULL)return lca2; 
    }
};
