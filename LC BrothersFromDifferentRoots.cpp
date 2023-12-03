/Back-end complete function Template for C++

class Solution
{
public:
    //Function to count the pairs from two BSTs whose sum is equal to given x.
    int countPairs(Node* root1, Node* root2, int x)
    {
        // Code here
        // checking if either of the roots is null, return 0.
        if (root1 == NULL || root2 == NULL)return 0;
        
        //creating two stacks to store nodes from each BST.
        stack<Node*> st1, st2;
        Node* top1, *top2;
        int count = 0;
        
        //iterating over the BSTs and storing nodes in stacks.
        while (1) {
            while (root1 != NULL) {
                st1.push(root1);
                root1 = root1->left;
            }
            while (root2 != NULL) {
                st2.push(root2);
                root2 = root2->right;
            }
            //if any of the stack is empty, break the loop.
            if (st1.empty() || st2.empty())break;
            
            //taking the top elements from both stacks.
            top1 = st1.top();
            top2 = st2.top();
            
            //if the sum of data of both nodes is equal to x.
            if ((top1->data + top2->data) == x) {
                //incrementing count and popping both elements from stack.
                count++;
                st1.pop();
                st2.pop();
                //updating the roots of BSTs.
                root1 = top1->right;
                root2 = top2->left;
            }
            //if the sum is less than x, pop the top from stack1 and move root1 to right.
            else if ((top1->data + top2->data) < x) {
                st1.pop();
                root1 = top1->right;
            }
            //if the sum is greater than x, pop the top from stack2 and move root2 to left.
            else {
                st2.pop();
                root2 = top2->left;
            }
        }
        //returning the count of pairs.
        return count;
    }
};
