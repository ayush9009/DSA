class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
       unordered_set<int>s1(nums1.begin(),nums1.end());
       unordered_set<int>s2(nums2.begin(),nums2.end());
       unordered_set<int>common;
       for(auto it:s1){
           if(s2.find(it)!=s2.end()){
               common.insert(it);
           }
       }
       int n=nums1.size();
       int n1=s1.size();
       int n2=s2.size();
       int c=common.size();
       return min(n,min(n1-c,n/2)+min(n2-c,n/2)+c);

    }
};
