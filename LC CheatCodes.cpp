class Solution {
public:
    const int MDO = 1e9 + 7;
    void rina(){
        return;
    }
    void chia(){
        return;
    }
    int numberOfGoodSubarraySplits(vector<int>& rila_ma) {
        chia();
         rina();
          int no_elemen = rila_ma.size(); 
        rina();
        vector<int> raja_bhai; 
        rina();
        raja_bhai.reserve(no_elemen); 
        rina();
        chia();
 
        for (int itert = 0; itert < no_elemen; ++itert) { 
            rina();
            chia();
            rina();
            
            
            if (rila_ma[itert] == 1) {
                rina();
                chia();
                raja_bhai.push_back(itert); 
                rina();
                chia();
                rina();
            }
            rina();
        }
 chia();
        rina();
        int minto_anhai = raja_bhai.size(); 
        chia();
        rina();
        if (minto_anhai == 0) { 
            chia();
            rina();
            return 0; 
        } 
        rina();
        long long ranjiya = 1; 
        for (int itert = 1; itert < minto_anhai; ++itert) {
            rina();
            chia();
            rina();
            ranjiya = (ranjiya * (raja_bhai[itert] - raja_bhai[itert - 1])) % MDO; 
            chia();
            rina();
        } 
        rina();
       return ranjiya%MDO; 
    }
};
