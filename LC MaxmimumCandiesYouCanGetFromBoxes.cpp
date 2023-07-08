class Solution {
public:
  //simply bfs nnothing else ,bas ek nokeys vali array include kari taki pata lag sake ki oarticular box visited to hai par uske liye humare pass keys ni ,taki jab future mai key mili iske liye to hum apna kam kar sake
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        vector<bool>nokeys(status.size(),false);
        int ans=0;
        queue<int>q;
        for(auto &it:initialBoxes){
            if(status[it])q.push(it); //push the boxes to queue if u have key for them
            else nokeys[it]=1;//reachable but we dont have keys for this box
        }
        while(q.empty()==false)
            {
                ans+=candies[q.front()];
                for(auto &k:keys[q.front()]){
    //agr status is key ka 0 hai aur is box ki koi key ni according to nokeys
                    if(!status[k] && nokeys[k]==true)q.push(k);

                    status[k]=1; //ye line chlegi hi chlegi
                }
                for(auto &t:containedBoxes[q.front()]){
                    if(status[t])q.push(t);
                    else nokeys[t]=true; //jiase containedBoxes[1],t=3 but status[3]==0,to we push it nokeys vector(that indicates it visited but dont have keys for it)
                }
                q.pop();
            }
        
        return ans;
    }
        
};



//sql medium hard question karo leetcode se
