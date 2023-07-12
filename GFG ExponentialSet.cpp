class Solution{   
public:
    long long int power(int a, long long int b) { 
        //complete the function here
         long long res = (long long)(std::pow(a, b));
        res = std::fmod(res, (long long)(1e9 + 7));
        return res;
        
    }
};
