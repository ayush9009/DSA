class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // CREATNG 2 VECTOR TO KEEP TRACK OF THE ELEMENTS 
        vector<int>left(26);
        vector<int>right(26);
        // A SET TO REMOVE SAME PALINDROMES
        unordered_set<string>uset;
        // COUNTING THE FREQUENCY OF ELEMENTS
        for(int i = 0 ; i <s.size(); i++)
        {
            right[s[i]-'a']++;
        }

        for(int i = 0 ;i<s.size();i++)
        {
            // as we started traversing we need to minus the frequency also
            right[s[i]-'a']--;
            // nowchecking if left and right have some elements same like left has a = 1 && right has a=3; so ofc it will be a palindrom  a_s[i]_a;
            for(int j = 0; j<26;j++)
            {
                if(left[j]>0 && right[j]>0)
                {
                    char x = 'a' + j; 
                    string pali = "";
                //  elements same like left has a = 1 && right has a=3; so ofc it will be a palindrom  a_s[i]_a;  
                    pali+=x;
                    pali+=s[i];
                    pali+=x;   
                    // now u will understand the above 3 lines 
                    
                    // IF THERE IS ALREADY A PALINDROME PRESENT LIKE THAT BEFORE THEN CONTINUE /IGNORE
                    if(uset.count(pali)==true)
                    {
                        continue;
                    }  
                    uset.insert(pali);
                }
            }
            left[s[i]-'a']++;
        }
        return uset.size();
    }
};
