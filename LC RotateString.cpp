class Solution {
public:
    bool rotateString(string s, string goal) {
        int flag =0;
        int i=0;
        int n=s.size()-1;
        if(s==goal)return 1;
        while(i!=n){
            //char tmp=s[0];
            //s[0]=s[s.size()-1];
           // s[s.size()-1]=tmp;

           s.push_back(s[0]);
           //s.pop_front();
           s.erase(0, 1);
            if(s==goal){
                flag=1;
                break ;
            }
            i++;
        }
        cout<<s<<endl;
        return flag;
    }
};
