 int ans = 2*min(x,y);
        bool flag = x+y - 2*min(x,y);
        ans = ans + z + flag;
        return ans*2;
