class Solution {
public:
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    bool findValid(int i,int j,vector<string>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && j>=0 && i<n && j<m)return true;
        return false;
    }
    int shortestPathAllKeys(vector<string>& grid) {
          int n=grid.size();
          int m=grid[0].size();
          int cnt=0,x=0,y=0;
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  if(grid[i][j]=='@'){
                      x=i;
                      y=j;
                  }
                  if(grid[i][j]>='a' && grid[i][j]<='f')cnt++;
              }
          }       
          queue<pair<set<int>,pair<int,int>>>q;
          map<pair<set<int>,pair<int,int>>,int>vis;
          set<int>key;
          int step=0;
          q.push({key,{x,y}});
          vis[{key,{x,y}}]=1;
          cout<<cnt<<endl;
          while(!q.empty()){
              int sz=q.size();
              while(sz--){
                  key=q.front().first;
                  x=q.front().second.first;
                  y=q.front().second.second;
                  q.pop();
                  if(grid[x][y]>='a' && grid[x][y]<='f')key.insert(grid[x][y]);
                  if(key.size()==cnt)return step;
                  for(int i=0;i<4;i++){
                      int nr=x+dr[i];
                      int nc=y+dc[i];
                      if(findValid(nr,nc,grid)){
                          if(grid[nr][nc]=='#')continue;
                          if(grid[nr][nc]>='A' && grid[nr][nc]<='Z' && key.find(tolower(grid[nr][nc]))==key.end())continue;
                          if(vis[{key,{nr,nc}}]!=1){
                              vis[{key,{nr,nc}}]=1;
                              q.push({key,{nr,nc}});
                          }
                      }
                  }
              }
              step++;
          }
          return -1;
    }
};
