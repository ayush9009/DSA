// Function to search a node in BST.

int floor(Node* root, int input) {
    if (root == NULL)
        return -1;
 
    // We found equal key
    if (root->data == input)
        return root->data;
 
    // If root's key is smaller, ceil must be in right
    // subtree
    if (root->data > input)
        return floor(root->left, input);
 
    // Else, either left subtree or root has the ceil value
    int ceil = floor(root->right, input);
    if(ceil==-1)return root->data;
    return  (ceil <= input) ? ceil : root->data;
}

// floor :same algo as ceil,bas ceil ka ulta yaha 
// floor:equal to x or just smaller than
