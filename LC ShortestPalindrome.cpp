// approach:We can construct the following string and run KMP algorithm on it:
// (s) + (some symbol not present in s) + (reversed string)

// After running KMP on that string as result we get a vector p with values of a prefix function for each character (for definition of a prefix function see KMP algorithm description). We are only interested in the last value because it shows us the largest suffix of the reversed string that matches the prefix of the original string. So basically all we left to do is to add the first k characters of the reversed string to the original string, where k is a difference between original string size and the prefix function for the last character of a constructed string.



// BHAI BHT KADAK QUESTION ON KMP
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s=s;
        reverse(rev_s.begin(),rev_s.end());
        string l=s + '#' + rev_s;
        vector<int>p(l.size(),0);
        for(int i=1;i<l.size();i++){
            //update the prefix boundary
            int j=p[i-1];
            while(j>0 && l[i]!=l[j]){
                j=p[j-1];  //move the last prefix boundary match
            }
            //if prefix boundary matches suffix boundary,increase prefix length

            if(l[i]==l[j]){
                p[i]=j+1;
            }
        }
        // p[l.size()-1] last index pai longest prefix length hogi jo hum l mai sai remove kar denge
        // aur jo kuch bachega use original (s)kai shru mai add kar denge
        //yani for example str=abab
        //reverse_s=baba
        //l=ababbaba   to longest prefix=aba of original string and suffix of rev_s=aba
        //so here these suffix and prefix are same first task is to find the length of prefix or
        // suffix,we find the  the longest prefix length using kmp partial match table
        //last element of this table is lengt of longest prefix
        //so now we remove the longest prefix i.e aba from l form last i.e now l=ababb
        //so remove the last b and append it to begining and the string u get now
        //is shortest palindrome i.e babab
        return rev_s.substr(0,s.size()-p[l.size()-1])+s;
        //s.size()-p[l.size()-1]  i.e baba-aba=b
        //now b+s=shortest palindrome
    }
};
