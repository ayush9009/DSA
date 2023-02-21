class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        vector<int>result;
        for(auto it:arr){
            result.push_back(it);
        }
        sort(result.begin(),result.end());
        result[0]=1;
        for(int i=1;i<result.size();i++){
            if(abs(result[i]-result[i-1])>1){
                result[i]=result[i-1]+1;
                cout<<"result[i]"<<result[i]<<" "<<"result[i-1]"<<result[i-1]<<endl;
            }
        }
        sort(result.begin(),result.end());
        return result[result.size()-1];
    }
};
