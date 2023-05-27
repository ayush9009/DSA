class UnionFind:
    def __init__(self, n):
        self.n = n
        self.parents = list(range(n))
        # self.counter = [1]*n
    def find(self, x):
        if self.parents[x] == x:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x != y:
            self.parents[x] = y
            # self.counter[y] += self.counter[x]
            # self.counter[x] = 0
        
def factor_list(n):
    factors = []
    for i in range(1,int(n**0.5)+1):
        if n%i==0:
            factors.append(i)
            if i!=n//i:
                factors.append(n//i)
    if 1 in factors:
        factors.remove(1)
    return factors

class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        n = len(nums)
        uf = UnionFind(n)
        mapp = defaultdict(lambda : -1)
        for i in range(n):
            fl = factor_list(nums[i])
            for j in fl:
                if mapp[j]!=-1:
                    uf.union(mapp[j],i)
                mapp[j] = i
        al = set([uf.find(i) for i in range(n)])
        return len(al)==1
