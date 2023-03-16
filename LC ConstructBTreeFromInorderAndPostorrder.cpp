class Solution {
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int is,int ie,int &index){
        if(is > ie)return NULL;
        int idx=0;
        TreeNode *root=new TreeNode(postorder[index--]);
        for(int i=is;i<=ie;i++){
            if(inorder[i]==root->val){
                idx=i;
                break;
            }
        }
        root->right=helper(inorder,postorder,idx+1,ie,index);
        root->left=helper(inorder,postorder,is,idx-1,index);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int is=0,ie=postorder.size()-1;
        int index=postorder.size()-1;
        return helper(inorder,postorder,is,ie,index);
    }
};
