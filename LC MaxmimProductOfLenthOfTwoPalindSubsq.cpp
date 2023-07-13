class Solution {
public:
//simple backtrack apporach,but u have to think in that direction to get the intution
    int result=0;
    bool isPalind(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(string &s,int i,string &s1,string &s2){
        if(i>=s.size()){  //means u try all the subsequencs
            if(isPalind(s1) && isPalind(s2)){
                result=max(result,(int)s1.size()*(int)s2.size());
            }
            return ;
        }
        s1.push_back(s[i]); //i pick s[i] for s1 not for s2,explore pathandstore result
        helper(s,i+1,s1,s2); //and then backtrack
        s1.pop_back();
        
        s2.push_back(s[i]); //i pick s[i]for s2 not for s1 explorepathstoreresult
        helper(s,i+1,s1,s2);//and then backtrack
        s2.pop_back();

        helper(s,i+1,s1,s2);  //3rd case means,i dont include s[i],i just explore and sotre result 
    }
    int maxProduct(string s) {
        string s1="",s2="";
        helper(s,0,s1,s2);
        return result;
    }
};
