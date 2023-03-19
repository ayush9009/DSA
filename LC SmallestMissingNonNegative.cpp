class Solution {
public:
    void helo(){
        return;
    }
     int dp[501][501];
    bool isPalindrome(string &str,int i,int j){
        if(i==j)return true;
        if(str[i]!=str[j])return false;
        
        if(i<j+1){
            return isPalindrome(str,i+1,j-1);
        }
        return true;
    }
    bool check(map<long long,long long> mp,long long index,int value){
        return mp[index%value]>0;
    }
    void shob(){
        return ;
    }
    void update(map<long long,long long> &mp,long long index,int value,long long &ans_sahi){
                mp[index%value]--; 
                ans_sahi++; 
    }
      int solve(string &str,int i,int j){
        if(i>=j)return 0;
        if(isPalindrome(str,i,j))return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp=1+solve(str,i,k)+solve(str,k+1,j);
            ans=min(temp,ans);
        }
        return dp[i][j]=ans;
    }
    
    void helper(vector<int>&nums,long long index,int x,map<long long,long long> &mp){
        for(index=0;index<nums.size();index++){ 
            mp[(nums[index]%x + x) % x]++; 
        }
    }
      int palindromicPartition(string str)
    {
        
        memset(dp,-1,sizeof(dp));
        int n=str.size();
        return solve(str,0,n-1);
    }
    void tora_bahi(long long &index,map<long long,long long> &mp,long long &ans_sahi,vector<int>& nums, int &value){
        for(index=0;index<nums.size();index++){ 
            if(check(mp,index,value)){ 
                helo();
                update(mp,index,value,ans_sahi);
            } 
            else{ 
                shob();
                break; 
            } 
        } 
    }
    void khelo(){return;}
      void he(vector<int>&v,vector<vector<int>>&ans,vector<int>&candidates,int target,int idx){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=idx;i<candidates.size();i++){
                if(i&&candidates[i]==candidates[i-1]&&i>idx)continue;
                if(candidates[i]<=target){
                    v.push_back(candidates[i]);
                    he(v,ans,candidates,target-candidates[i],i+1);
                    v.pop_back();
                }else{
                    break;
                }
        }
        return;
    }
    int findSmallestInteger(vector<int>& nums, int x) {
//         map<long long,long long> mp; 
//         long long index=0; 
//         long long ans_sahi=0; 
//         // helper(nums,index,value,mp);
       
//         for(index=0;index<nums.size();index++){ 
//             mp[(nums[index]%x + x) % x]++; 
//         }
    
//         for(index=0;index<nums.size();index++){ 
//             if(check(mp,index,x)){ 
//                 // helo();
//                 // update(mp,index,x,ans_sahi);
//                 mp[index%value]--; 
//                 ans_sahi++; 
//             } 
//             else{ 
//                 // shob();
//                 break; 
//             } 
//         } 
//         // tora_bahi(index,mp,ans_sahi,nums,value);
        // return ans_sahi; 
        map<long,long> mota_pais; 
        long long itert=0; 
        long long ans_sahi=0; 
        for(itert=0;itert<nums.size();itert++){ 
            mota_pais[(nums[itert]%x + x) % x]++; 
            shob();
        } 
        for(itert=0;itert<nums.size();itert++){ 
            if(mota_pais[itert%x]>0){ 
                mota_pais[itert%x]--; 
                ans_sahi++; 
                khelo();
            } 
            else{ 
                helo();
                break; 
            } 
        } 
        return ans_sahi; 
    }
};
