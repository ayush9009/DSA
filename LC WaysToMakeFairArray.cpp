class Solution {
public:
 //easy question+observations also
    int waysToMakeFair(vector<int>& nums) {
        int cnt = 0;
		int n  = nums.size();
		int ev_Sum = 0, od_Sum = 0;
		vector<int> evn(n);
		vector<int> od(n);

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				ev_Sum += nums[i];
			} else od_Sum += nums[i];

			evn[i] = ev_Sum;
			od[i] = od_Sum;
		}
       int ans=0;
    //    int n=nums.size();
       for(int i=0;i<nums.size();i++){
           if(i==0){
               int nos=evn[n-1]-nums[0]; // 0 remove kara to jo 0 kai bad ka jo element tha vo ab 0 pai agya yani
            //    odd sum kya huha evn[n-1]-nums[0]
                 //deko bhai agr i==0,last temr minuse nums[0] to ab jo
            //    yani 0 vale ko remove karke ab nums[n-1]-nums[0] hojaga
               int nes=od[n-1]; //odd to odd hi rahega koi dikkt ni

               if(nos==nes)ans++;
               continue;
           }
           int nes=evn[i-1]+od[n-1]-od[i];  //shuru kai to same yani i se pahle to same rehange uske bad inedx peechey hoja
        //    to even sum=odd sum, aur ab jo odd usm vp even sum hogya 
           int nos=od[i-1]+evn[n-1]-evn[i]; 

           if(nes==nos)ans++;
       }
       return ans;
    }


