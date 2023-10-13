class Solution{
public:
    int out;
    void inOrder(Node* node, int x){
        if(!node)
            return;
           
        inOrder(node->left, x);
        if(node->data <= x)
            out = node->data;
        else
            return;
        inOrder(node->right, x);
    }
    int floor(Node* root, int x) {
        out = -1;
        inOrder(root, x);
        return out;
    }
}
