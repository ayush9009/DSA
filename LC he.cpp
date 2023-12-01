/* The Node structure is
struct Node {
int data;
Node * right, * left;
}; */
class Solution{
  public:
// Function to create sets for leaf and non-leaf nodes
    void make(set<int> &l,set<int> &n,Node *root)
    {
        if(root==NULL)
            return;
        
        // adding current node data to the non-leaf set
        n.insert(root->data);
        
        // if current node is a leaf node, add its data to the leaf set
        if(root->left==NULL and root->right==NULL)
        {
            l.insert(root->data);
            return;
        }
        
        // recursively calling make function for left and right children
        make(l,n,root->left);
        make(l,n,root->right);
        
    }
    
    /*You are required to complete below method */
    // Function to check if a dead end exists in the binary tree
    bool isDeadEnd(Node *root)
    {
        // Creating sets for leaf and non-leaf nodes
        set<int> leaf,node;
        make(leaf,node,root);
        
        // Adding 0 to the non-leaf set
        node.insert(0);
     
        // Checking if there is a dead end by comparing adjacent nodes in the leaf set
        for(auto i = leaf.begin();i!=leaf.end();i++)
        {
            int ii = (*i);
            
            // If the node before and after the current leaf node exist in the non-leaf set, return true
            if(node.find(ii-1)!=node.end() and node.find(ii+1)!=node.end())
                return true;
        }
        
        // If no dead end found, return false
        return false;
    }
};
