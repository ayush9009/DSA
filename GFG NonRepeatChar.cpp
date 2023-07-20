class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
          unordered_map<char,int> m;
       for(auto i:S) m[i]++;
       for(auto i:S)
       {
           if(m[i]==1) return i;
       }
       char c='$';
       return c;
       
    }

};
