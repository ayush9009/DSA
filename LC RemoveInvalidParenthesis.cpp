class Solution {
public:
//first of all in this by reading question we understand we have to consider all the cases ,when we have to consider all the cases first apporach came into our mind is recursion
//so here we find all that stuff recusively but smartly how,what we do in recusion either we remove it or not remove,
// but we dont know how many times we remove any parenthesis ,so if we dont know this so there are many cases arises,
// so what we can do here we find count of parennthis that make the string valid,so now we know okay if we remove that much amount of parenthes from string i get valid string ,this is one thing.
// now we know min removal of invalid parenthesis,so for every parenthesis we check we remove it or not(we do this now also,but now we know na how many times we do this,if we dont know then size of recusion increases)
// suppose ()())() you are at index=1(0 bases indexing)and count =1(count of min. invalid parenthis),so we remove index=1 element and then string is valid or not,what is string now,left part and right part
// left part=s.substr(0,i) i conider ni hoga kuki i is vo index jo hum remove kar rai
// right part=s.substr(i+1)means from i+1 to string size,since we remove 1 parenthis so we decrement the count of min.removal

//base case if min removal <0 so return
// but this is okay we remove the that parenthesis but when we check the validity of string when min.removal=0(kuki jab tak zero ni honge tab tak koi na koi string mai hi jo gadbad kar ra ek bar min.remval==0 to hume check kar sake ,ki 
// string is valid or not)
//if min.removal==0


// deko min rremoval count hai apke pas,now aap check kar rai ,if we remove this,or we remove another parenthis
// to if we reomve parenthis to is vale kai liye count=count-- hogi ab recusively phir check karo iske liye if 
// count!=0 to koi aur ko remove karke check karo then phir recusively check jab count ==0 ki string valid hai ya ni
// bhai recusively check kar rai to kahi cases mai count=0 lakin string not valid hogi to vo sab check karna
vector<string>result;
unordered_map<string,int> mp;
int minRemoval(string s){
  stack<char>st;
  int i=0;
  while(i<s.size()){
    if(s[i]=='(')st.push(s[i]);
    else if(s[i]==')'){
      if(st.empty()==false && st.top()=='(')st.pop();
      else st.push(')');
    }
    i++;
  }
  return st.size();
}
void helper(string s,int count){
  if(mp[s]!=0)return ;
  else mp[s]++;  //to avoid dulicacy
  if(count<0){
    return;
  }
  if(count==0){
    if(minRemoval(s)==0){  //means string is valid
      result.push_back(s);
    }
    else return;
  }
  for(int i=0;i<s.size();i++){
    string left=s.substr(0,i);
    string right=s.substr(i+1);
    helper(left+right,count-1);  //count-1 kuki ek bar to remove kar diya aapne
  }
  return;
}
    vector<string> removeInvalidParentheses(string s) {
        int count=minRemoval(s);
        helper(s,count);
        return result;
    }
};
