class Solution{   
public:
    int minimumStep(int n){
        //complete the function here
         int ans = 0;
        //loop until n is greater than 1.
        while(n > 1){
            //if n is divisible by 3, reduce n to one-third its value and increment ans.
            if(n % 3 == 0){
                ans++;
                n /= 3;
            }
            //if n is not divisible by 3, reduce n by 1 and increment ans.
            else{
                n--;
                ans++;
            }
        }
        //return the minimum steps required to reach 1 from n.
        return ans;
    }
};
