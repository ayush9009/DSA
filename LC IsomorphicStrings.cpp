class Solution{   
public:

//VVIP GOOOGLE,AMAZON,FACEBOOK
    // foo bar example
    // f->b             b->f
    // o->a             a->o r->o
    // o->r (ab jaise hi ispe ayegi to hum dekenge okay map mai to o already exist kar ra aur map vo a ki sath but now when we check we see o is aleady exist but mp[s[i]]!=t[i]
    // means mp[o]==r jo ki false hai kuki mp[o]=a so we return false)             
    bool isIsomorphic(string s, string t) {
       unordered_map<char,char>mp1,mp2;
       for(int i=0;i<s.size();i++){
        //    ye if tab chlega agr mp mai pahle se koi element exist kar ra ya ni
        //agr kar ra to chelga nahi to nahi

           if(mp1.find(s[i])!=mp1.end() && mp1[s[i]]!=t[i])return false;
           if(mp2.find(t[i])!=mp2.end() && mp2[t[i]]!=s[i])return false;
           mp1[s[i]]=t[i];
           mp2[t[i]]=s[i];
       }
       return true;
    }
};
