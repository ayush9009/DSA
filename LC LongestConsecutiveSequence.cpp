class Solution {
public:
//approach:deko 1 prev 0 exist ni karta to 1 se chain shuru ho sakti h
//ab deko arr=[3,4,5,6,2,1]
//to 3 prev 2 to yani chain 2 se shuru ho sake so we ignore 3
//to 4 pai aye 4 prev 3 aur 3 ka prev 2 to continue karo kuch na karo
//aise hi5,6 2, kai liye
//1 aya to 1 prev not exit so we search its next ,we see 2 exist so count++ then we get 3,4,5,6 so on
//so we get the count;
    int longestConsecutive(vector<int>& nums) {
        //consecuctive means ek bad ek like 1,2,3,4 and 101,102,103 etc.

       int  ans=0;
       unordered_set<int>s;
       for(int i=0;i<nums.size();i++)s.insert(nums[i]);
       for(int i=0;i<nums.size();i++){
           int cur_element=nums[i];//3
           int prev_element=cur_element-1;//2 if we get the previous element then we ignore,kuki vo jo uska 
           int count=0;   //hai us sey chain shuru ho jagi
           if(s.find(prev_element)==s.end()){//if we dont get previous ,and we get it next element so we 
               while(s.find(cur_element)!=s.end()){ //then we maintain a chain ,
                   cur_element++;
                   count++;
               }
           }
           ans=max(ans,count);
       }
       return ans;
    }
};
