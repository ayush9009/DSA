class Solution{
  public:
	void shuffleArray(int arr[],int n)
	{
	    int  i = n/2 - 1;
        for (int j = n-1; j >= n/2; j--) {
            arr[j] <<= 10;
            arr[j] |= arr[i];
            i--;
        }
        
        i = 0;
        for (int j = n/2; j < n; j++) {
            int num1 = arr[j] & 1023;
            int num2 = arr[j] >> 10;
            arr[i] = num1;
            arr[i + 1] = num2;
            i += 2;
        }
	}
};
