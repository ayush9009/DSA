class Solution {
public:
    // qyestion badiya hai, pahle socha
    bool canReach(string s, int minJump, int maxJump) {

        // ek diff array kahlo , taki  pta ho ki is current index se
        //  kaha se kaha tak ja sake, ab rahi bat ye ki is suppose koi index pai
        //  jump karke suppose aap aye to kya aa bhi sakte hai, means it's
        //  reachable or not, to vo cummulative array se pata lag jaga, jo ki
        //  differnece array ki madath se bnegi ,kuki diff array vo range bta ve
        //  jah hum ja sake, based on range , and value kuki 0 hai to hi ja sake
        //  na.

        // tc: o(n), sc:o(n)
        int cnt = 0, n = s.size();
        if (s[n - 1] == '1')
            return false; // not reachable
        vector<char> diff(n, 0);
        for (int i = 0; i < n; i++) {
            cnt += diff[i]; // apply ye prefix ki trah se bnti jari, basedon
                            // diff array

            // current index pai sirf tab aa sake, agr, cnt>0 and s[i]='0'
            //    else not
            //    aur suppose agye to ab iski liye range update kardo ki
            //    kahasekaha ja sake
            if (i == 0 ||
                (s[i] == '0' &&
                 cnt > 0)) { // 0 islie kuki 0 se hi0 pai jump kar sako,else not
                // to hum yaha se deke kaha tak ja sake
                // to uske liye diff aray bhi update karenge using 1,-1
                //  1 - starting point, last index jo hoga ,vaha tak paoch usey
                //  agle ko -1 that denotes kya ni aa sakte
                // mark the jump as reachable using
                if (i + minJump < n) {
                    diff[i + minJump] += 1;
                if(i + maxJump + 1 < n)   
                    diff[i + maxJump + 1] -= 1;
                        // just agle index pai -1, denotes isey pahle
                    // vale tak ja sake bas
                }
            }
        }
        // deko cnt bnri bassed on diff array, diff array bn ri basd on range
        // and s[i], to uske hisab se karo, to agr cnt jo current index kai liye
        // , >0 to hi vi reachable to that point else not
        // atleast one valid path reach the last index.
        return cnt > 0;
    }
};