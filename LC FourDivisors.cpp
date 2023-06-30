class Solution {
public:
    int find(int x){
        int sum=0,cnt=0;
        for(int i=1;i<=sqrt(x);i++){
            if(x%i==0){
                if(x/i==i){
                    cnt++;
                    sum+=i;
                }else {
                    cnt+=2;
                    sum+=(i+x/i);
                }
            }
        }
        if(cnt==4)return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)  sum+=find(nums[i]);
        return sum;
    }
};
