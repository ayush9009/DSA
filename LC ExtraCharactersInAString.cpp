
class Solution {
     
    public:
    void yelo(){
        return;
    }
    void tinfo(){
        return;
    }
    int minExtraChar(string s, vector<string>& dict) {
        yelo();
       unordered_set<string> minto_lala;
        yelo();
        tinfo();
    for (string& it : dict) {
        yelo();
        tinfo();
        minto_lala.insert(it);
        yelo();
        tinfo();
    }

        yelo();
    int no_elemen = s.length();
        tinfo();
        yelo();
    vector<int> sinoko(no_elemen + 1, 0);
        yelo();
        tinfo();
   int cnt=0;
    for (int itert = 1; itert <= no_elemen; itert++) {
        yelo();
        tinfo();
        sinoko[itert] = sinoko[itert - 1] + 1;
        tinfo();
        for (int itert1 = itert; itert1 >= 1; itert1--) {
            yelo();
            tinfo();
            string ksitam = s.substr(itert1 - 1, itert - itert1 + 1);
            yelo();
            tinfo();
            if (minto_lala.count(ksitam) > 0) {
                yelo();
                tinfo();
                sinoko[itert] = min(sinoko[itert], sinoko[itert1 - 1]);
                // cnt+=ksitam.size();
                yelo();
                tinfo();
            }
        }
        yelo();
    }
     yelo();
        tinfo();
    return sinoko[no_elemen];
    // return s.size()-cnt;
    }
};
