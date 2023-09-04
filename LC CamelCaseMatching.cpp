class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        set<char>st;
        for(char i='A';i<='Z';i++){
            st.insert(i);
        }
        vector<bool>result;
        for(int i=0;i<queries.size();i++){
            int flag=0,p1=0;
            for(int k=0;k<queries[i].size();k++){
                if(queries[i][k]==pattern[p1]){
                    p1++;
                }
                else if(st.find(queries[i][k])!=st.end()){ 
                    //jasie FootBallTest,FoBa
                    // F,F matches p++,o match to p++ contirl aya T but match ni kara
                    // pattern mai kisi se aur st mai hai already ans.push(false)
                    result.push_back(false);
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                if(p1==pattern.size()){   //FooBar,FoB ya p=3 hogya  
                    result.push_back(true);
                }else{  //kuki is case mai p1!=pattern.size()
                    result.push_back(false);
                }
            }
        }
        return result;
    }
};
