class Solution {
public:
// some cases 
// "00123"->123
// "-123"->-123 //negative so store -ve in some variable,and append it with result in last
// "  123"->123  //remove the leading white spaces
// "123 are my words"->123
// "heloo 123"->0   means if first are words then digits then ignore it and return 0
// ""->0
// "2147483652" means greater than 2^31-1 so we return 2^31-1(i.e 2147483647)

    bool isDigit(char ch){
        return ch>='0' && ch<='9';
    }
    int myAtoi(string s) {
       int len=s.size();
       if(len==0)return 0;
       int i=0;
       while(i<len && s[i]==' '){
           i++;
       }
       bool isNeg=0;  //if 1 means number is -ve , or if 0 means postivie
       if(i<len){
            if(s[i]=='-'){
              i++;
              isNeg=1; //reprsenting negative
            }else if(s[i]=='+'){
                i++;
            }
       }
       int ans=0;
       while(i<len && isDigit(s[i])){
        
           int dig=s[i]-'0';
        //    digit>7 ? because
        //    input = 2147483646
        //    ouptput=2147483647
//   expected ouptput=2147483646
   
//    to yani agr last digit >7 to return INT_MAX else 
//    INT_MAX=   2147483647
//    INT_MAX/10=214748364  ,to yaha digit=7 to vohi check kar rai ans==INT_MAX/10 aur dig=7 ho chuki to is case mai INT_MAX return kar do accordinglt
   cout<<INT_MAX/10;

           if(ans > (INT_MAX/10) || (ans==INT_MAX/10 && dig >7)){
               return isNeg?INT_MIN:INT_MAX;
           }
           ans=(ans*10) + dig;  
        //    123,  0*10+1=1     1*10+2=12     12*10+3=123

           i++;
       }
       return (isNeg)?(-ans):ans;
    }
};
