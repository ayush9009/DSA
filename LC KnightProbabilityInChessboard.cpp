class Solution {
public:
    
     //bahatreen question
     map<vector<int>,double>mp; //it stores the precomputaions
    //  dekiye ek particular row col pai knight dubare aa sake to us pointse humdubare 
    //  ku valid points(mtlb knight kaha kaha ja sakta vo cheez hummd dubare ku nikale)
     vector<pair<int,int>>directions={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};  //ye sari directions hai jinme knight ja sakta hai
     
    double dfs(int r,int c,int n,int k){
        double in=0;
        if(k==0){  
            if(r>=0 && r<n && c>=0 && c<n){
            in++;//yani ki is direction mai knight movekare sake to cnt incremtnkardo
            return in;
        }
        }
        if(r<0 || c<0 || r>=n || c>=n)return 0; //invalid case
       
        vector<int>v={r,c,k};
        // for(auto it:v.size())cout<<it<<" ";
        if(mp.find(v)!=mp.end())return mp[v];
        for(auto it:directions){
            int dr=r+it.first;  //ye vo row jisme hume chck karnaknight ja sake ya ni
            int dc=c+it.second; //ye vo col jisme hume chck karnaknight ja sake ya ni
            in+=dfs(dr,dc,n,k-1); //k-1 kuki ek move to karliya apne jakr
        }
        return mp[v]=in;//particular row,col,k mai humne store karliya itni jagah
        //knight ja sakta hai

    }
    double knightProbability(int n, int k, int row, int column) {
        double total=pow(8,k);
        double in=dfs(row,column,n,k);
        double ans=in/total;
        return ans;
    }
};
