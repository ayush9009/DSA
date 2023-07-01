class Solution {
public:
    bool checkPowersOfThree(int n) {
       int x=1;
       stack<int>st;
       while(x<=n){     
           //1,3,9,81,729
        //    eg:12
           st.push(x);//1,3,9
           x*=3;
       }
       int sum=0;
       while(!st.empty()){
        //    9<12 sum+=9,9+3<=12 sum+=9+3,sum=12 12+1!<3 to we come 
        //    out of stack
           if(sum+st.top()<=n)sum+=st.top();
           st.pop();
       }
    //    12==12
       return sum==n;
  
    }
};


