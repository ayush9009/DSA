class Solution
{
	public:
		string is_palindrome(int n)
		{
		    // Code here.
		    string str=to_string(n);
		    string ans=str;
		    reverse(str.begin(),str.end());
		    if(ans==str)return "Yes";
		    else return "No";
		}
};
