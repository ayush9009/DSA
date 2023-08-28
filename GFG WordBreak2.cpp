class Solution {
public:
    // bht hi jada kadak question
    //VVIP QUESTION (we can do this using dp but trie is most efficient)
//  deko jaise catsanddog,kuki trie mai cat exist kar rai na ki c to sirf cat kai liye we=1 hoga to hum check kar rai trie if c exist no so move forward a existno so move forward and so on we reach t ,now we see cat exist so we make partition and now we recuseively call for anddog suppose we reach at g we see it exist in trie and now pos==s.size() so we push this catand dog string in our answer,but note one thing
// while making recursive call add spcae also
// recursively check karte jare are when we reach end of string we backtrack taki sari possiblitiles cover kar sake ,we can do this using dp but trie is most efficient apporach

    vector<string>ans;
    struct trienode{
        char c;
        int we; //count words
        trienode *child[26];
        trienode(char c){
            we=0;
            this->c=c;
            for(int i=0;i<26;i++)child[i]=NULL;
        }
    };
    trienode *root;  //root of trie
    void insertInTrie(string &word){
        trienode *cur=root;
        int idx;
        for(int i=0;i<word.size();i++){
            idx=word[i]-'a';
            if(!cur->child[idx]) //means this node not already exist so we create it
            cur->child[idx]=new trienode(char(97+idx));

            cur=cur->child[idx];
        }
        cur->we+=1;// since we store this whole word in trie so we increment itsconut
    }
    bool searchInTrie(string s){
        trienode *cur=root;
        int idx;
        for(int i=0;i<s.size();i++){
            idx=s[i]-'a';
            if(!cur->child[idx])return false; 
            // if this letter not exist to agey ki string alsonotxistso return false
            cur=cur->child[idx] ;
        }
        return cur->we>0;
    }
    void solve(const string &s,string st,int pos){
        if(pos==s.size()){
            ans.push_back(st);
            return; //backtrack so that we find other possibilite aslo
        }
        st+=" "; //cat kai bad spaca add kar diya 
        for(int i=pos;i<s.size();i++){
            if(searchInTrie(s.substr(pos,i+1-pos)))
            solve(s,st+s.substr(pos,i+1-pos),i+1);
        }
    }

    vector<string> wordBreak(int n, vector<string>& wordDict, string s){
        root=new trienode('/');
        for(auto it:wordDict){
            insertInTrie(it);  //sab trie mai insert kar diye
        }
        for(int i=0;i<s.size();i++){
            if(searchInTrie(s.substr(0,i+1)))  
            solve(s,s.substr(0,i+1),i+1);
        }
        return ans;
    }
};
