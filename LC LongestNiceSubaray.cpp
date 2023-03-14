class Solution {
public:
    //BADIYA QUESTION ON SLIDING WINDOW
    // 1 3 8 48 10
    // jab continouse array ki bat aye to sabse pahle sliding window dimag mai ani chaiye
    // to j=0 pai rako aur i ko j se agey rako
    // to num|=nums[i] to num=01(binray representation) agli bar aye to apne deka 3->11 (01 & 11) !=0
    // to 1 remove kardo num se why we remove 1 not 3 kuki continouse suarry chaiye,to 1 kaise remove karogey
    // num=01 num=num^num[j++] yani01^01 ki sath to num=0 xor ki madth se num mai sai vo number remove kar sake
    // jo dikt dera ,ab num|=num[i] therfore num=3,ab  3&8==0 ans=2-1+1=2,ab num=1011,ab 1011&110000=0
    // to num=111011 hogya to i=3 and j=1 to i-j+1=3-1+1=3 to ans=3 aise hi 10 kai liye kar lena
    // lakin maximum ans=3 to return 3
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0;
        int j=0;
        int num=0;
        for(int i=0;i<nums.size();i++){
            while((num & nums[i])!=0){  //agr 0 nhi hai to problem hai to j ko rmeove kar do,kuki cont.arry
            //chaiye,to kaise remove kar j xor kuki xor kya karega 11=0 00=1
                num ^=nums[j++];
            }
            num |=nums[i];  //agr zero hai to add kardo num mai that's set kardo num ko
             //or ki madath se num set kar diya
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
