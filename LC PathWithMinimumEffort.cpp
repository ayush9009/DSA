class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
       int n=heights.size();
       int m=heights[0].size();
       vector<vector<int>>eff(n,vector<int>(m,1e9));
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       eff[0][0]=0;
       pq.push({0,{0,0}});
       int drow[]={-1,0,1,0};
       int dcol[]={0,1,0,-1};
       while(pq.empty()==false){
           int effort=pq.top().first;
           int row=pq.top().second.first;
           int col=pq.top().second.second;
           pq.pop();
           if(row==n-1 && col==m-1)return effort;
           for(int i=0;i<4;i++){ //charo directions mai jake dekenge jaha minimum effort vaha chle jayegne
              int nrow=row+drow[i];
              int ncol=col+dcol[i];
              if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                  int newEffort=max(effort,abs(heights[nrow][ncol]-heights[row][col]));
                  if(newEffort < eff[nrow][ncol]){//particular node kai effort ko update kar rai
                  //jo ki initally har node ka INT_MAX h
                      eff[nrow][ncol]=newEffort;  //aaccoring to example 1
                    //   for node 3(row=1col=0) iske vazah se 8(row=1,col=1) and 5(row=2 col=0) pq mai push hogye ab lakin pq mai top mai minimum vala hoga i.e 5 to iske dwar aminimum path mil jaga hume

                      pq.push({newEffort,{nrow,ncol}});
                  }
              }
           }
       }
       return 0;
    }
};
    // //agr yaha min leve to agey kahani hi ni badegi,hum har ek case check karna chave isliye max nahi to jiase node 3 and node 8 to max=effort,abs(height[3]-height[8])=max(2,5)=5 tabhi to 8 vali node ki
    //               value set hogi else agr min lete to hum to sirf node pai hi rah jate
