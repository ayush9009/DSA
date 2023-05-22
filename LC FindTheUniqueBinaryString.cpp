class Solution {
public:
    string result="";
    void helper(string str,int indx,vector<string>&nums){
        if(result!="")return;  //base cases
        if(indx==nums.size()){ //we need only nums.size() string,not less or more than it
           if(find(nums.begin(),nums.end(),str)==nums.end())
               result=str;
            return;
           
        }
        helper(str+'0',indx+1,nums);
        helper(str+'1',indx+1,nums);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string str;
        helper(str,0,nums);
        return result;
    }
};
