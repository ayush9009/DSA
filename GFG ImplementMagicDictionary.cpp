class TrieNode{
      public:
          TrieNode* children[26];
          bool isEnd;

          TrieNode(){
              memset(children, NULL, sizeof(children));
              isEnd = false;
          }
};
class MagicDictionary {
public:
   TrieNode* root;
    
    MagicDictionary() {
        root=new TrieNode();    
    }
    void insert(string word){
        TrieNode* node=root;
        for(auto c:word){
            if(node->children[c-'a']==NULL)
            node->children[c-'a']=new TrieNode();

            node=node->children[c-'a'];
        }
        node->isEnd=true;
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto word:dictionary){
            insert(word);
        }
    }
//simple trie implemenation nothing else,but ek bool varible aur lliye ,jo ye batayega ki ek bar replace kara ya ek se jada bar
// suppose trie dict= hello ,str=hello 
// h matched,e matched l matched l macthed o matched now index==str.size()
// so we return isEnd && isReplaceable,or kkuki is reaplceabla=false,kuki koi character reaplace ni huha to false return ho jaga

// suppse trie dict= hello ,str=hell size=4
// to l tak sab matching ho jagi ,lakin last l kai bad index>=4 but isEnd=false,kuki 
// dictionary mai hello hai na hell taki after o we get isEnd=true not after l so we simply return false

// suppose trie dict =hello ,str=hhllo size=5
// h matched ,now e!=h to yaha isReplaceable ko true karo aur baki string match karo,i.e(llo) vo sab match kar jange
// now index>=5 and isEnd=true,isRepalce=true so we simply return true

// suppse trie dict =hello,str=hhmllo size=5 
// h matched ,now e!=h to yaha isReplaceable ko true karo aur baki string match karo,
// now l!=m but isReplaceble =true,to hum baki kis aur mai checking karenge,since to hum check karte rahnge loop ki madath se m hai kya hello mai kkahi to nahi mila if else vali condition chlne ki ni in the end,for loop end ho jaga and we simply return res, i.e false



    bool helper(string str,TrieNode* node,int index,bool isReplaceable){
        if(index>=str.size())return node->isEnd && isReplaceable;
        TrieNode* cur=node;
        bool res=false;
        int curIndex=str[index]-'a';
        for(int i=0;i<26;i++){
            if(cur->children[i]){
                if(curIndex==i){
                    res=helper(str,cur->children[i],index+1,isReplaceable);
                }else if(isReplaceable==false){
                    res=helper(str,cur->children[i],index+1,true); //true means humne ek character replace kar diua aur ab baki string match kar rai,ab koi replace ni ho sakta ,kuki sirf ek character replace kar sakte hai
                }
            }
            if(res)return true;
        }
        return res;
    }
    bool search(string  str) {
        return helper(str,root,0,false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
