class Solution {
public:
    int solve(int x,int y){ // 12 15
        int z=x^y;  //3
        int count=0;
        while(z){
            z=z&(z-1);  //3&2=2 ,count=1  2&1=0,count=2,lopp breaks so we return
            count++;
        }
        return count;
    }
    int totalHammingDistance(vector<int>& nums) {
        // shift by one places and then do and with a number
        int ans=0;
       for(int i=0;i<32;i++){
           int ze=0,on=0;
           for(auto it:nums){
               if(it & (1<<i))   //first shift then and so that we come to know 0th bit is diff or not
            //    if diff to output one else 0
               on++;
               else ze++;
           }
           ans+=on*ze;
       }
       return ans;
    }

};
