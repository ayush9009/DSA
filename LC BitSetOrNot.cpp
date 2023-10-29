class Solution
{
    public:
    bool checkKthBit(int n, int k)
    {
        return (n&(1<<k));  //1 ki sath and karke deklo us position ka pata lg jaga set or not
    }
};
