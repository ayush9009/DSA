class Solution {
public:
//ye question thoda tricky star ne bnaya aur  kuch ni
//ye we can do this by stack but here we use two stack why?
//becasue ek stack se hum left aur right bracket check kar lete ,lakin agr inhe balance karna using star,to star ko bhi
// store karna jaori,acha yaha hum indx karenge why?
//deko (* ye possible ho sake by doing () aise ,lakin agr *( to ise kaise balnce karogey )( ya phir (( to not balcned
//to yaha indx store karne padenge taki hum check kar sake if left bracket('(') index > star index or not
    bool checkValidString(string s) {
        stack<int>open,star;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')open.push(i);//simply push karte jare right bracket aur star
            else if(s[i]=='*')star.push(i);
            else{//mtlb right bracket agya to open ko pop karo agr vo empty ni hai to,agr open epmty hogya
            //to star pop karo (kuki ho sake tumne bina star kai balcen kar diya to ab star pop karne padenge na)
                if(open.empty()==false)open.pop();
                else if(star.empty()==false)star.pop();
                else return false; //means open and star is empty now,but now we get ) so we cannot manage it soreturn false
            }
        }//is loop se we maintain all the right(')') brackets,
        //is loop se bahar ane ka mtlb apne sare right bracket manage kar diye,lakin abhi aise bhi ho sake ,
        // ki left bracket bach rai open stack mai to unhe manage karnna padega

        //now process from right to left ,checking if left bracket ('(')is left in open stack or not
        //if it is there in open stack we manage it using star stack.

        while(open.empty()==false){
            if(star.empty())return false; //seedhi si bat star se hum balance karenge ,agr star nihtobalancingnot possible

            else if(open.top() < star.top()) { //means star should be on right side *( aap btao kaise balance karogey
            // ise not possible lakin agr (* ab balance kar sako () aise karke to star index must be greater than right
            // bracket index 
            open.pop();
            star.pop();
            }
            else{
                return false; //ye case hai right bracket index < star index to bhai false hi ayega
            }
        } 
        return true;
    }
};
