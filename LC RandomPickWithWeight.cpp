class Solution {
public:
    //cumulative sum bucket concept 
    // 1 2 3  
    // if we start from 0
    // 0+1=1,1+2=3,1+2+3=6
    // 0 1 3 6 to ye cumulative sum hai ,we have to find the random index
    // (rangeof 1 is from 0-1),rangeof3 is 1-3 and range of 6 is from 3-6
    // suppose we make 6 random choice in that choice one number is 4(rand() se mil jaga ye)
    // ab hume dekna in range mai se vo number kis mai exist kar ra jis range mai exist karega vo hum 
    // return kar denge
    // for ex that number exist in 3-6 so we return index2
    // but how do we come to know this number exist in this bucket or range
    // for that we can use liner seach but it takes O(n) time
    // so we can use binary search or upper bound both take logn time
    // bucket ranges from 0-sum
    // approach .first we find cumulative sum,then bucket,then random index,then using uppebound we get ansr
    vector<int>result;
    Solution(vector<int>& w) {
        result.push_back(w[0]);
        for(int i=1;i<w.size();i++){
        result.push_back(result.back()+w[i]);  //mtlb result[i]=result[i-1]+w[i]
        }
    }
    
    int pickIndex() {
        int rand_number=rand()%(result.back());//result.back() kuki cumusum range from 0-sum(6)
          //randomw index milgya ab using upperbound 
        // we check in bucket what is required index
        return upper_bound(result.begin(),result.end(),rand_number)-result.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
