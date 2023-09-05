class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        long long cnt=0,sum=0;
        unordered_map<long long,long long>mp; //sum,cnt
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==0){
                cnt++;
            }
            
            if(mp.find(sum)!=mp.end()){
                cnt+=mp[sum];
            }
            
            mp[sum]++;
            
            // mp.insert(sum)1;
        }
        return cnt;
        // 0,1 mp[0]++ 2,3 mp[0]++; i.e mp[0]=2 and cnt=3 now,sum+=5,mp[5]++ i.e mp[5]=1,now sum+=5,i.e sum=10
        // mp[10]++ mp[10]=1,sum+=arr[i],ie sum=10 already exist socnt+=mp[sum],cnt+=1 i.e cnt=4,mp[10]++,mp[10]=2
        // now sum+=arr[i] i.e sum=10 already exist cnt+=mp[10],cnt+=2i.e cnt=6,so return cnt
    }
};
