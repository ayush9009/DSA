class Solution {
public:  
//    BHT BADIYA QUESTION ON DP+BINARY TREES
   // memoistation code   
    // unordered_map<TreeNode*,int>memo;
    // int helper(TreeNode* root){
    //     if(root==NULL){
    //         return 0;
    //     }
    //     if(memo.count(root))return memo[root];
    //     int ans_including_root=root->val;
    //     if(root->left!=NULL){
    //         ans_including_root+=helper(root->left->left)+helper(root->left->right);
    //     }
    //     if(root->right!=NULL){
    //         ans_including_root+=helper(root->right->right)+helper(root->right->left);
    //     }
    //     int ans_excluding_root=helper(root->left)+helper(root->right);

    //     int ans=max(ans_excluding_root,ans_including_root);

    //      memo[root]=ans;

    //      return ans;
    // }
    // here we return pair i.e {root_include,root_not_include}
    //optimised code
    pair<int,int>helper(TreeNode*root){
        if(root==NULL)return {0,0};

        pair<int,int>left=helper(root->left);  //ye hai {a,b}  b means root not incude,a means root include
        pair<int,int>right=helper(root->right); //ye hai {x,y} x means root include ,y means root not include

        int root_house_robbed=root->val+left.second+right.second;
        //  xuppose we have root h and its left rreturn {a,b} and right return {x,y}
         //ek answer i.e q=h->Val+b+y(jab root include )
         //ek anser i.e p=max(a,b)+max(x,y) when root nont icldue
        //if root not iclude to max(a,b)+max(x,y)
        int root_house_not_robbed=max(left.first,left.second)+max(right.first,right.second);

        pair<int,int>ans;
        ans.first=root_house_robbed,ans.second=root_house_not_robbed;
        return ans;
    }
    int rob(TreeNode* root) {
        pair<int,int>result=helper(root);
        return max(result.first,result.second);
        // return helper(root);
    }
};
