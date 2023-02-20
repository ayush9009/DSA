class Solution {
public:

//how many mhts possible 
//there can be atmost one mht is possible if the number of nodes is even
//there can be atmost two mht is possible if the number of nodes is odd
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        if(n==0)return {};
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            auto u=it[0];
            auto v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1)q.push(i);
        }
        vector<int>result;
        while(q.empty()==false){
            int n=q.size();
//example1:0,1,2,3   to bhai ye deko minimum height tree atmost 2 possible hai
//0 indegree=1, 2 indegree=1, ,3 indegee=1 but 1 indegree=3
//0,2,3 all are leaves nodes inki madath se jo truee bnega vo mht ni dega
//agr 1 ki bat kare to mht mil jayega ye observation se pata chlega
//ab deko result.push(0) uska adjacent 1 but iski indegre==3 to reduce karo jab tak 1 na ho ja
//deko filhal queue mai 0,2,3 in sabka adjacent 1 to uski indegree reduce karte jao jab tak 1 na ho ja
//hum bar bar result mai push karte jare kuki hume ni pata kab vo mht ki node mi ja
//to jab sabke adjancet traverse ho jagey to vo node mil jagi isliye to indegree[mht node]=1 hogi aur
// 0,2,3 pop ho chuke ab quuemai sirf 1 hai ,for(i,n)pura hogya to reuslt.clear () chla gya
// ab queue mai sirf 1 to sirf uske liye queuemai jayege aur result.push_Back(1) aur uske adjacetindegre=1 to lopse bahar
//aqueu empty to rreturn result
            result.clear();
            for(int i=0;i<n;i++){
                int cur=q.front();
                q.pop();
                result.push_back(cur);
                for(auto it:adj[cur]){
                    if(--indegree[it]==1){
                        q.push(it);
                    }
                }
            }
        }
        return result;
    }
};
