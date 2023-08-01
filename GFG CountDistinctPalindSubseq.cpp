class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
      
       
    //   a b c d c b a
    //   0 1 2 3 4 5 6
    //   if(s[0]==s[6]),agr sahi to since palindomrice subsrque to i+1,j,
    //   to ab i=1 se i=5 tak ek bar,phir i=0tak sab subsequneces h
       int N = str.length();

    int cps[N + 1][N + 1];
    memset(cps, 0, sizeof(cps));
    for (int i = 0; i < N; i++)cps[i][i] = 1;
    for (int L = 2; L <= N; L++) {
        for (int i = 0; i <= N-L; i++) {
            int k = L + i - 1;
            if (str[i] == str[k])
                cps[i][k]
                    = cps[i][k - 1] + cps[i + 1][k] + 1;
            else
                cps[i][k] = cps[i][k - 1] + cps[i + 1][k]
                            - cps[i + 1][k - 1];
        }
    }
    return cps[0][N - 1];
    }
     
};
