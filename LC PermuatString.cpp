class Solution{
    public:
        void permutations(string str, int i, int n,vector<string>&v)
    {
        // base condition
        if (i == n - 1)
        {
            v.push_back(str);
            return;
        }
    
        // process each character of the remaining string
        for (int j = i; j < n; j++)
        {
            // swap character at index i with current character
            swap(str[i], str[j]);       // STL swap() used
    
            // recurse for string [i+1, n-1]
            permutations(str, i + 1, n,v);
    
            // backtrack (restore the string to its original state)
            swap(str[i], str[j]);
        }
    }
    
    
    vector<string> permutation(string S)
    {
        vector<string> v;
        permutations(S,0,S.length(),v);
        sort(v.begin(),v.end());
        return v;
    }
       
};
