class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // vector<int>result;
        // if(pref.size()<2)return pref;
        // result.push_back(pref[0]);
        // for(int i=0;i<pref.size()-1;i++){
        //     result.push_back(pref[i] ^ pref[i+1]);
        // }
        // return result;
        vector<int>result;
        if(pref.size()<2)return pref;
        result.push_back(pref[0]);
        for(int i=0;i<pref.size()-1;i++){
            result.push_back(pref[i]^pref[i+1]);
        }
        return result;

    }
};
