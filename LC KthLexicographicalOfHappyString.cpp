class Solution {
public:
    string getHappyString(int n, int k) {
        //idea is to use queue data structure to store all the lexicographically sorted strig till length n & at last we will get the kth string if present else we will return empty string

       queue<string>q;
       q.push("a");
       q.push("b");
       q.push("c");
       while(q.front().size()<n ){
           string res=q.front();
           q.pop();
           if(res[res.size()-1]!='a')q.push(res+'a');  //frist we check if a,then b then c,why we do this in manner so that we get lexicographically shortest string
           if(res[res.size()-1]!='b')q.push(res+'b');
           if(res[res.size()-1]!='c')q.push(res+'c');
       }
       
    //    while(!q.empty()){
    //        cout<<q.front()<<" ";q.pop();
    //    }
       string ans="";
       while(!q.empty() && k>0){
           if(k==1){
               ans=q.front();break;
           }
           q.pop();
           k--;
       }
       return ans;
        
    }
};
