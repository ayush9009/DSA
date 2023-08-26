class Solution {
  public:
void dfs(int i,long sum,long prev,string num,vector<string>&ans,string sumPath,int target){
    if(i==num.size()){
        if(sum==target){
            ans.push_back(sumPath);
        }
        return;
    }
    for(int j=i;j<num.size();j++){
        if(j>i && num[i]=='0'){
            // avoid leading zeros
            break;
            
        }
        long number=stol(num.substr(i,j-i+1));
        string tempPath=num.substr(i,j-i+1);

        if(i==0){
            //if it is first index measn i.e "732" to i=0 means 7 hai to j+1bas
            dfs(j+1,number,number,num,ans,tempPath,target);
        }else{
            dfs(j+1,sum+number,number,num,ans,sumPath + '+' + tempPath,target);
            dfs(j+1,sum-number,-number,num,ans,sumPath + '-' + tempPath,target);
            dfs(j+1,sum-prev+(prev*number),(prev*number),num,ans,sumPath + '*' + tempPath,target);
        }
    }
}
    vector<string> addOperators(string num, int target) {
        // code here
        
        vector<string>ans;
        dfs(0,0,0,num,ans,"",target);
        return ans;
    }
};
