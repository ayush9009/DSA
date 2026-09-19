class Solution {
public:
//agr traverse karte karte akri mai poach gye iska mtlb ussey pahle ka sab 
//palindromes to vo string consider
// ho sake 
//index 1 pai cut mara ,to 0 to 1 palindrome h ki nahi check karo, agr nahi hai to pahle usey banao palindrome, supose hai ,to 2 to n-1 deka jaga na
//  means aabb
//  to agr maine 2 pai cut mara left = aab right=b, 
//  to cut marne ka koi fayda ni kuki cut vaha marunga taki left vala palidnromeho to rahe kamm se kam right na , ho to right phir marunga
//  means aabc to maine - aa,b,c par aab,c ka to kuch fayda ni check karke kuki left vala hi ni palindrome hum 0 index se shuru karke n-1 tak jayenge
//  aur suppose n-1 tak paoch gye to humara safar sahi raha, ye string lelo
//  aa,b,c c pai paooch gye to theek
//  aab,c,pach hi ni paneka c pai kuki aab palindrome ni to cut lagne ka ni

//  isliye cut kailiye jarior ki left vala palind kuki left se right mai are
//  phir right vale kai recusion call hoga, usme cuts lagenge usey paldinrome banayeg
//a|a|b|b| u reach index=3 where u can make partiotn , to and n-1 to isliye 
// return this whole , a,a,b,b,


    bool isPalind(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    void helper(string s, int idx, vector<string>&res,vector<vector<string>>&ans){
        if(idx==s.size()){//means aab hai to aap idx=3 means b ayi to ab vaha cut
        // mara, vaha to tabhi sambhav hai na agr left sab paldinrome
            ans.push_back(res);
            return; //kuki we reach end onlyw hen whole is palind
        }
        
        for(int i=idx;i<s.size();i++){
            if(isPalind(s,idx,i)){ //left part = idx to i, rigt part i+1,n-1
            //to left palind hai tohi is index pai cut marne ka fayd else agey badho
               res.push_back(s.substr(idx, i-idx+1));
               helper(s,i+1,res,ans);// right i+1 se leke n ab uspe cut marne ktry
               res.pop_back(); //backtrack kiya to aur strings bhi consider ho sake
            //    means auppse a/a/b/b kar diya 
            //    par ek ye bhi to ho sake aa/b/b to isliye backtrack to consider each
            //    string
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<string>res;
        vector<vector<string>>ans;
        helper(s,0,res,ans);
        return ans;
    }
};