#define ll long long

class Solution {
public:
    int cnt;
    void dfs(int i,vector<vector<int>>&adj,vector<int>&vis){
        vis[i]=1;  //now it's is visited
        cnt++;//kuki is component ka ye node h to cnt++
        for(auto v:adj[i]){
            if(!vis[v])dfs(v,adj,vis);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); //ye bn gyi adjaceny list
        }
        // example 2: 1 component->4 nodes,2nd component->1 node(3) ,3 component->2 nodes(1,6)
        // ye cnt hmne result mai dal di,ab ye btao comonent 2 se kon connected nhi hai 4 nodes,copmponet 3 
        // (1node+4node)*2 multiplu by 2 kuki 2ndoes(1,6 hai na isliye) total4+5*2=14,sirf rigth ki traf se dek ra
        //mtlb 3- se kon not connected h,1,6 se kon not connect vo dekha 0,2,5,4 se jo not connected hai vo isliye
        // nhi dekha to avoid duplicacy
        vector<int>res;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt=0;
                dfs(i,adj,vis);
                res.push_back(cnt);    //ye result mai hum dal rai ek connected component kai andar kitne comp h
            }
        }
        ll ans=0,preSum=0,siz=res.size();
        for(int i=0;i<siz;i++){
            ans+=res[i]*preSum;
            preSum+=res[i];
        }
        return ans;
    }
};
