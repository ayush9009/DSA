// struct Node{
//     Node *links[26];
//     bool flag=false;
//     bool containsKey(char ch){
//         return (links[ch-'a']!=NULL);
//     }
//     void put(char ch,Node* node){
//         links[ch-'a']=node;
//     }
//     Node* get(char ch){
//         return links[ch-'a'];  //basically we return th reference of that character
//     }
//     void setEnd(){
//         flag=true;
//     }
//     bool isEnd(){
//         return flag;
//     }
// };
// // TRIE(AYUSH-SHARMA,SECTION-B,ROLL_NO-66)
// class Trie {
// private: 
//     Node* root;
// public:

//     // Trie *root;
//     Trie() {
//         //creating new obeject
//         root=new Node();
//     }
    
//     void insert(string word) {
//         //initalialistion dummy point to root initially
//         Node* node=root;
//         for(int i=0;i<word.size();i++){
//             if(!node->containsKey(word[i])){
//                 node->put(word[i],new Node());//ek node bneig aur jo ye character usme us node mai iska refernce hoga
//             }
//             //moves refernce to trie
//             node=node->get(word[i]);
//         }
//         node->setEnd();
//     }
    
//     bool search(string word) {
//         Node *node=root;
//         for(int i=0;i<word.size();i++){
//             if(!node->containsKey(word[i])){
//                 return false;
//             }
//             node=node->get(word[i]);  //taki agle refernce pai badte rahve check kanre kai liye
//         }
//         return node->isEnd();
//     }
    
//     bool startsWith(string prefix) {
//         Node *node=root;
//         for(int i=0;i<prefix.size();i++){
//             if(!node->containsKey(prefix[i])){
//                 return false;
//             }
//             node=node->get(prefix[i]);
//         }
//         return true;
//     }
// };
struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);   //if it nuull then that character is not found
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;        //node li uska referce new trie se jod diya
    }
    Node* get(char ch){
        return links[ch-'a'];   //jo links hai mtlb jo node character vali create hui vo jise point kar ri vo reutrn kar do
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private:
    Node* root;                        //root bnana to jarori tree ka
    public:
    Trie(){
        root=new Node();   //creating object
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))return false;
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string prefix){
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i]))return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};
