class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
       queue<int>q;
       vector<string>result;
       map<string,int>mp;
       q.push(id);
       
       vector<int>visited(friends.size(),0);
       visited[id]=1;
       while(q.empty()==false && level--){

           int n=q.size();
           for(int i=0;i<n;i++){
               int u=q.front();
               q.pop();
               for(auto v:friends[u]){
                   if(!visited[v]){
                       visited[v]=1;
                       q.push(v);
                   }
               }
           }
       }
         //   pahle particular lvel pai gye uske bad ,us level pai jo humare friends thai
        //    sirf vo hai queue mai ,aur unhone jjo vidos vo humne map mai store kar li
       //now the quue have only the friends of required level
       vector<pair<int,string>>res;
       while(q.empty()==false){
           for(string &it:watchedVideos[q.front()]){
               mp[it]++;
           }
           q.pop();
       }
      
       for(auto it=mp.begin();it!=mp.end();it++){
           res.push_back({it->second,it->first});
       }
       sort(res.begin(),res.end());
       transform(res.begin(),res.end(),back_inserter(result),[](pair<int,string>&p){return p.second;}); 
       //ye stackoverflowsechapayetransformfuncpairs<string,int>koconvertkardegavector<string>

       return result;
    }
};
