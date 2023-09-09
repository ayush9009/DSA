class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n=queries.size();
        vector<int>result;
        int maxi=items[0][1];
        for(auto &t:items){
            maxi=max(maxi,t[1]);
            t[1]=maxi;  ///beauty maxi
        }
        for(int i=0;i<queries.size();i++){
            int left=0,right=items.size()-1;
            int x=queries[i],count=0;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(items[mid][0]<=x){
                    count=mid+1;
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
            if(count==0)result.push_back(0);
            else result.push_back(items[count-1][1]);
            
        }
        return result;
    }
};
