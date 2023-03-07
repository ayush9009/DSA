class Solution {
public:
    int parent[1001];
    int rank[1001];
    void dsu(int n){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int findParent(int x){
        if(parent[x]==x)return x;
        return parent[x]=findParent(parent[x]);
    }
    void Union(int x,int y){
        // cout<<"all"<<x<<" "<<y<<" ";
        int parx=findParent(x);
        int pary=findParent(y);

    //    cout<<"tall"<<parx<<" "<<pary<<" ";

        if(parx==pary)return;

        int rankx=rank[parx];
        int ranky=rank[pary];

        if(rankx>ranky)parent[pary]=parx;
        else if(ranky>rankx)parent[parx]=pary;
        else{
            parent[parx]=pary;  //yo kardiya parent[0]=2
            rank[pary]++;    //aur 2 ki rank badha di
        }
    }
    
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
       dsu(n);
       vector<bool>res(requests.size());
       for(int i=0;i<requests.size();i++){
           int a=requests[i][0];
           int b=requests[i][1];

           int para=findParent(a);
           int parb=findParent(b);

           int flag=0;
           
           for(int j=0;j<restrictions.size();j++){
            //    cout<<"hello"<<restrictions[j][0]<<endl;
               int tmp1=findParent(restrictions[j][0]);
            //    cout<<tmp1<<endl;
               int tmp2=findParent(restrictions[j][1]);
            //    cout<<tmp2<<endl;


                //  cout<<"hum hai don"<<" "<<para<<tmp1<<parb<<tmp2;
               if((para==tmp1 && parb==tmp2)  || (para==tmp2 && parb==tmp1)){
                   
                   flag=1;
                   break;
               }
           }
           if(flag==0){
               Union(a,b);
               res[i]=true;
           }
           else{
               res[i]=false;
           }
       }
       return res;
    }
};
//for request:
//for restrictions
//now in union find ,if u get the request j child/parent of restricts i then return false;
