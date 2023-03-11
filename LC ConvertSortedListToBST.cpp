class Solution {
public:
    TreeNode* traverse(vector<int>&result,int start,int end){
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(result[mid]);
        root->left=traverse(result,start,mid-1);
        root->right=traverse(result,mid+1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
         vector<int>result;
        if(head==NULL)
            return NULL;
       ListNode *curr=head;
        while(curr!=NULL){
            result.push_back(curr->val);
            curr=curr->next;
        }
        return traverse(result,0,result.size()-1);
    }
};
