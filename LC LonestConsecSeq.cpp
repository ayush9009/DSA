class Solution {
public:
// sorting + logic se nlogn
// withoutsorting + hashmap se n
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int maxi=0;
        int cnt=0;
        for(auto it:nums){
            st.insert(it);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end() ){ //means it may be the starting element of our longest consec. sequence
                int x=it;
                cnt=1;
                while(st.find(x+1)!=st.end()){  //taki longest mil jaye
                    x=x+1;
                    cnt=cnt+1;
                }
                maxi=max(maxi,cnt);
            }
        }
        // although we used two nested loops ,but in worst case set travered atmost twice
        // see example : 10 20 30 (to aap dek sako innter loop ek hi bar chle har element kai liye) isliye ya tc:o(2*n) kuki atmost twice ja sake
    //  first iteration of   first loop(10) se then
    //   first oteration oof ineer loop 10+1 not exist
    //   second iteration of first loop(20) then 
    //   first oteration oof ineer loop 20+1 not exist
    //   third iteration of first loop(30) then
    //   first oteration oof ineer loop 30+1 not exist

        return maxi;
    }
};
