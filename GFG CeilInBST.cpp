// User function Template for C++

// Function to return the ceil of given number in BST.
// algo:
// if(rootNULl)return -1
// if(root==x)return x
// if(root<x)to yani right mai hoga
// if(root>x)to left mai hoga ,ya to node jo equal x kai vo milegai ya just greater milegi to us case mai wer
// return ceil else we return root->data becaue that is our answer
int findCeil(Node* root, int input) {
    if (root == NULL)
        return -1;
 
    // We found equal key
    if (root->data == input)
        return root->data;
 
    // If root's key is smaller, ceil must be in right
    // subtree
    if (root->data < input)
        return findCeil(root->right, input);
 
    // Else, either left subtree or root has the ceil value
    int ceil = findCeil(root->left, input);
    return (ceil >= input) ? ceil : root->data;
   
}
//  (ceil >= input) ? ceil : root->data; is line ko smjne kai liye ki why we reutrn root->Data see below example
 
// example1 hai lakin x=4 hai to iska answer 5
