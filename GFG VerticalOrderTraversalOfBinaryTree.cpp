class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
   
     vector<int> verticalOrder(Node *root){
        map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        vector<int>ans;
        while(q.empty()==false){
            pair<Node*,int>res=q.front();
            Node* tem=res.first;
            int dist=res.second;
            mp[dist].push_back(tem->data);
            q.pop();
            if(tem->left){
                q.push({tem->left,dist-1});
            }
            if(tem->right){
                q.push({tem->right,dist+1});
            }
        }
        for(auto it:mp){
            vector<int>res=it.second;
            for(auto t:res)ans.push_back(t);
        }
        return ans;
     
        

    
    }
};
