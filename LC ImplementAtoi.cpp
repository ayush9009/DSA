class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int x=0,cnt=0;
        string st;
        for(int i=0;i<str.size();i++){
            if(str[i]>='0' && str[i]<='9'){
            x=x*10+str[i]-'0';
            st+=str[i];
            }
            else if(str[0]=='-' && cnt==0){
                st+=str[i];
                cnt++;
            }
        }
        
        // cout<<x;
        if(st.size()==str.size()){
            if(str[0]=='-')return -x;
            else return x;
        }
        // return x;
        return -1;
    }
};
