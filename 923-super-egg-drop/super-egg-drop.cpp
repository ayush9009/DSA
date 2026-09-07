class Solution {
public:
    //    int dp[101][10001];
    //    long long helper(int e, int k){
    //     if(e==1)return k;
    //     if(k==1 || k==0)return k;
    //     long long mini=INT_MAX;
    //     if(dp[e][k]!=-1)return dp[e][k];
    //     for(int f=1;f<=k;f++){
    //         //egg break
    //         long long low=0,high=0;
    //         if(dp[e-1][f-1]!=-1){
    //             low=dp[e-1][f-1];
    //         }else{
    //             low=helper(e-1,f-1);
    //         }

    //         if(dp[e][k-f]!=-1){
    //             high=dp[e][k-f];
    //         }else{
    //             high=helper(e,k-f);
    //         }

    //         long long temp = 1+max(high,low);

    //         mini = min(mini,temp);
    //     }
    //     return dp[e][k] = mini;
    //    }
    int dp[101][10001];
    long long helper(int e, int k) {
        if (e == 1)
            return k;
        if (k == 1 || k == 0)
            return k;
        long long mini = INT_MAX;
        if (dp[e][k] != -1)
            return dp[e][k];
        int low = 1, high = k;
        while (low <= high) {
            int f = (low + (high - low) / 2);
            int egBrk = helper(e - 1, f - 1);
            int notBrk = helper(e, k - f);

            long long temp = max(egBrk, notBrk);

            mini = min(mini, temp);

            if (egBrk > notBrk) { // means jada high fllors
                // to floor kam karo
                high = f - 1; // means f--
            } else {
                low = f + 1; // upr kai fllors try karo f++
            }
        }
        return dp[e][k] = 1 + mini;
    }
        int superEggDrop(int e, int k) {
            memset(dp, -1, sizeof(dp)); // memset mai -1,0 hi rakh sako.
            // binary saerch se dek rai ,kuki minmum ek move to kareogey
            //  maximum k moves
            // ab spose not eggBrk = 5
            //  eg brak =8 to egg break vala jada aya ,means jada high floor
            //  se kahi bar try kiya to hume neeche ana chaiye that is f-1 karna
            //  chaiye

            // ab not eggBrk = 8
            // eggBrk = 5
            // not egg brk jada aya means neeche kai neeche floors try kar rai
            // to upr jao , floor bahdao,

            // basically eggBrk~=noteggbreak ,means , kam jada bhi ho sake ,
            //  ab agr
            //  breakCase = 5
            // notBreakCase = 6

            // to 6 vala lelenge kuki in the end hume max ko hi to minimum karna

            // Isliye binary search breakCase aur notBreakCase ke beech balance
            // point ke paas jaati hai, kyunki humein max() ko minimum karna
            // hai.

            return helper(e, k);
        }
    };