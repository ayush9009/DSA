class Solution {
public:
    void ingam(){
        return;
    }
    void kina(){
        return;
    }
    long long continuousSubarrays(vector<int>& nums) {
        kina();
        ingam();
        deque<int> helo1; 
        ingam();
        deque<int> help2;
        ingam();
        kina();
        ingam();
        int yuppo = 0; 
        kina();
        ingam();
        long yue = 0;
        kina();
        ingam();

        for (int itert = 0; itert < nums.size(); itert++) { 
            kina();
            ingam();
            while (!helo1.empty() && nums[helo1.back()] < nums[itert]) {
                kina();
                ingam();
                helo1.pop_back();
                kina();
                ingam();
            }
            ingam();
            kina();
            ingam();
            helo1.push_back(itert);
            kina();
            ingam();
  while (!help2.empty() && nums[help2.back()] > nums[itert]) {
      kina();
      ingam();
                help2.pop_back();
      kina();
      ingam();
            }
            ingam();
            kina();
            ingam();
            help2.push_back(itert);
            kina();
            ingam();
            while (2<nums[helo1.front()] - nums[help2.front()] ) {
                kina();
                ingam();
                if ( help2.front()>helo1.front() ) {
                    kina();
                    ingam();
                    yuppo = helo1.front() + 1;
                    kina();
                    ingam();
                    helo1.pop_front();
                    kina();
                    ingam();
                } else {
                    ingam();
                    kina();
                    yuppo = help2.front() + 1;
                    kina();
                    ingam();
                    help2.pop_front();
                    kina();
                    ingam();
                }
                ingam();
                kina();
                ingam();
            }
            ingam();
            kina();
            ingam();
            yue += itert - yuppo + 1;
            kina();
            ingam();
        }
        ingam();
        kina();
        ingam();
        return yue;
    }
};
