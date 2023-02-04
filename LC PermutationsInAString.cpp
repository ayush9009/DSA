class Solution {
public:
  
   //BADIYA QUESTION ON STRINGS

    bool matching_vectors(vector<int>a,vector<int>b){
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return false;
        vector<int>mp1(26,0);
        vector<int>mp2(26,0);
        for(auto it:s1){
            mp1[it-'a']++;
        }
        int i=0,j=0;
        // note:j-i+1 ye isliye kara jara kuki 0 based indexing hai 
        while(j<s2.size()){
            mp2[s2[j]-'a']++;  //store the freq in currentfreqwindow
            if(j-i+1==s1.size()){  //if window size==s1.size then check if window and s1 charcters
            // frequnies are equal or not
                if(matching_vectors(mp1,mp2))return true; //if match directly reutrn true
            }
            if(j-i+1<s1.size())j++;   //if window size less than s1.sizesoincrementthewindowsizei.ej
            else{//means window size is greater than or equal to s1.size()
                mp2[s2[i]-'a']--;  //freq of start decreases
                i++; //make the next window
                j++;
            }
            
        }
        return false;
    }
};
