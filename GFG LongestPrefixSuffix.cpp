class Solution{
  public:		
//KMP ALGORITHM FOR STRING MATCHING
	int lps(string s) {
	    // Your code goes here
	    int n=s.size();
	    vector<int>lps(n,0);
	    int i=1,len=0;
	    while(i<n){
	        if(s[i]==s[len]){
	            len++;
	            lps[i]=len;
	            i++;
	        }else{
	            if(len>0){
	                len=lps[len-1];
	            }else{
	                lps[i]=0;
	                i++;
	            }
	        }
	    }
	   return lps[n-1];
	    
	}
};
