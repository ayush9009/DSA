class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans = ""; 
      ans += A[0];
      
      queue<char>q;
      q.push(A[0]);
     
      int arr[26] = {0};
      arr[A[0]-'a']++;
      
      for(int i=1;i<A.size();i++)
      {
          arr[A[i]-'a']++;
          if(arr[A[i]-'a'] == 1) q.push(A[i]);
         while(!q.empty() and arr[q.front()-'a'] != 1)
         {
              q.pop();
         }
        if(q.empty())
          ans += '#';
        else
          ans += q.front();
      }
      return ans;
		}

};
