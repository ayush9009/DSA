class Solution {
public:
    int totalMoney(int n) {
        int count=0;
        int prev=0;
        while(n-7 >= 0){
            count += 7*8/2;
            count += prev;
            n-=7;
            prev += 7;
        }

        prev /= 7;
        while(n>0){
            prev++;
            count += prev;
            n--;
        }
        return count;
    }
};
