class Solution {
public:
    
    char nextGreatestLetter(vector<char>& letters, char target) {
       int start=0,end=letters.size()-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(target<letters[mid])
                end=mid;
            else
                start=mid+1;
        }
        if(letters[start]>target)
            return letters[start];
        else
            return letters[0];
    }
};
