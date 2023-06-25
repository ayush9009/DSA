class Solution {
public:
    int t[101][201];
    int MOD = 1e9+7;
    int helper(vector<int> &locations, int i, int finish, int fuel){
      if(fuel<0) return 0; //Exit case.
      long long result= 0;
      if(t[i][fuel]!=-1) return t[i][fuel]%MOD;
      // Now checking all the possible path.
      for(int itert = 0;itert<locations.size(); itert++){
        if(itert==i) continue;
        result = (result%MOD +  helper(locations, itert, finish, fuel-abs(locations[itert]-locations[i]))%MOD)%MOD;
      }

      //During return we have to is idx ==  finish.
      if(i==finish) return t[i][fuel] = (1 +  result)%MOD;
      return t[i][fuel] = result%MOD;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
       memset(t, -1, sizeof(t));
       return helper(locations, start, finish, fuel); 
    }
};
