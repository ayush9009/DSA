class Solution {
public:
    // graph ,bfs find the shortest path
    
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>indicesOfValue;
        for(int i=0;i<n;i++)indicesOfValue[arr[i]].push_back(i);  // 100->0,4 ; -23->1,2
        vector<bool>visited(n);
        visited[0]=true;
        queue<int>q;
        q.push(0);
        int steps=0;  //ye humara answer hai
        while(q.empty()==false){
            for(int size=q.size();size>0;size--){
                int i=q.front();
                q.pop();
                if(i==n-1)return steps;  //reach to destination or last index
                vector<int>&next=indicesOfValue[arr[i]];
                next.push_back(i-1);
                next.push_back(i+1);  
                //next mai sab push kar diya ab next ko traverse karenge aur check valid h ya nhi
                for(int j:next){
                    if(j>=0 && j<n && !visited[j]){
                        visited[j]=true;
                        q.push(j);
                    }
                }
                indicesOfValue[arr[i]].clear();
            }
            steps++;  //mtlb queue mai jo tha uske liye check hogya isliye cnt++
        }
        return steps;
    }
};
