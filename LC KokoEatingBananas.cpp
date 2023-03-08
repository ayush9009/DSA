class Solution {
public:
    typedef long long ll;
    ll check(vector<int>& piles,ll mid){
        ll count=0;
        for(int i=0;i<piles.size();i++){
            count+=ceil((1.0*piles[i])/mid);
        }
        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ll n = piles.size();
        ll l=1, r=1e12;
        while(l<=r){
            ll mid = (l+r)/2;
            if(check(piles, mid) <= h){
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return l;
    }
};
