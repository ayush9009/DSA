class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        bool ans=true;
        int visited=-1;
        int count;
        vector<int>result;
        for(int i=0;i<arr.size();i++)
        {
            count=1;
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[i]==visited)
                    break;
                else if(arr[i]==arr[j])
                {
                    count++;
                    arr[j]=visited;
                }
            }
            if(arr[i]!=visited)
                result.push_back(count);
        }
        for(int i=0;i<result.size();i++)
        {
            for(int j=i+1;j<result.size();j++)
            {
                if(result[i]==result[j]&&result[i]!=0)
                    ans=false;
            }
        }
        return ans;
    }
};
