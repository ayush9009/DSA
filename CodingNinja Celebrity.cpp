#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B)
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise
*/

int findCelebrity(int n) {
 	// Write your code here.
	 vector<int>indegree(n);
	 vector<int>outdegree(n);
	 for(int i=0;i<n;i++){
		 for(int j=0;j<n;j++){
                   if (knows(i, j)) {
                     indegree[j]++;
                     outdegree[i]++;
                   }
                 }
	 }
	 int celeb=-1;
	 for(int i=0;i<n;i++){
		 if(indegree[i]==n-1 && outdegree[i]==0){
			 celeb=i;
			 break;
		 }
	 }
	 return celeb;
}
