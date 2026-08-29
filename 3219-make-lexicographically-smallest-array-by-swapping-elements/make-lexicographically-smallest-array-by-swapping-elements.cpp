// Priority Queue (min-heap) contains: {1, 0}, {3, 2}, {5, 1}, {9, 3}, {8, 4}
// Processing the Priority Queue
// First Iteration:

// topp = pq.top() → topp = {1, 0}
// Pop topp from pq → pq becomes {3, 2}, {5, 1}, {9, 3}, {8, 4}
// pq.top() → {3, 2}
// Check abs(pq.top().first - topp.first) <= limit:
// abs(3 - 1) = 2 (within limit)
// Perform ds.unionBySize(topp.second, pq.top().second):
// ds.unionBySize(0, 2)
// Second Iteration:

// topp = pq.top() → topp = {3, 2}
// Pop topp from pq → pq becomes {5, 1}, {9, 3}, {8, 4}
// pq.top() → {5, 1}
// Check abs(pq.top().first - topp.first) <= limit:
// abs(5 - 3) = 2 (within limit)
// Perform ds.unionBySize(topp.second, pq.top().second):
// ds.unionBySize(2, 1)
// Third Iteration:

// topp = pq.top() → topp = {5, 1}
// Pop topp from pq → pq becomes {9, 3}, {8, 4}
// pq.top() → {8, 4}
// Check abs(pq.top().first - topp.first) <= limit:
// abs(8 - 5) = 3 (not within limit)
// No union performed
// Fourth Iteration:

// topp = pq.top() → topp = {8, 4}
// Pop topp from pq → pq becomes {9, 3}
// pq.top() → {9, 3}
// Check abs(pq.top().first - topp.first) <= limit:
// abs(9 - 8) = 1 (within limit)
// Perform ds.unionBySize(topp.second, pq.top().second):
// ds.unionBySize(4, 3)
// Result of Union-Find Operations
// After these operations, the connected components are:
// Component 1: indices 0, 1, 2
// Component 2: indices 3, 4
// Creating the Result Array
// Group Indices by their Ultimate Parent:

// cpp
// Copy code
// unordered_map<int, vector<int>> mp;
// for (int i = 0; i < n; ++i) {
//     mp[ds.findUltimateParent(i)].push_back(i);
// }
// mp will contain:
// Parent 0: [0, 1, 2]
// Parent 3: [3, 4]
// Sort Each Group and Create Final Answer:

// cpp
// Copy code
// for (auto it : mp) {
//     auto vec = it.second;
//     sort(vec.begin(), vec.end());
//     vector<int> temp;
//     for (auto ind : vec) temp.push_back(arr[ind]);
//     sort(temp.begin(), temp.end());
//     int i = 0;
//     for (auto ind : vec) {
//         ans[ind] = temp[i];
//         ++i;
//     }
// }
// For Parent 0: Indices [0, 1, 2] → Elements [1, 5, 3] → Sorted Elements [1, 3, 5]
// Assign: ans[0] = 1, ans[1] = 3, ans[2] = 5
// For Parent 3: Indices [3, 4] → Elements [9, 8] → Sorted Elements [8, 9]
// Assign: ans[3] = 8, ans[4] = 9
// Final Result
// The final array is [1, 3, 5, 8, 9].
// Dry Run Summary
// Here's a concise summary of the dry run:

// Initialization:

// Priority Queue: {1, 0}, {3, 2}, {5, 1}, {9, 3}, {8, 4}
// Disjoint Set: Initial state
// Iterations:

// Iteration 1: Union indices 0 and 2
// Iteration 2: Union indices 2 and 1
// Iteration 3: No union (difference exceeds limit)
// Iteration 4: Union indices 4 and 3
// Result Construction:

// Components: {0, 1, 2} and {3, 4}
// Sorted Components: [1, 3, 5] and [8, 9]
// Final Array: [1, 3, 5, 8, 9]


class DisjointSet{
    public:
    vector<int>parent,rank,size;

        DisjointSet(int n ){
            rank.resize(n+1,0) ;
            parent.resize(n+1) ;
            size.resize(n+1,1) ;
            for(int i=0 ; i<=n ; i++){
                parent[i] = i ;
            }
        }

        int findUltimateParent(int node){
            if(node == parent[node]) return node ;
            // Doing path compression
            return parent[node] = findUltimateParent(parent[node]) ;
        }

        // We have node u and node v which i have to combine
        void unionByRank(int u , int v){
            int ultiPar_u = findUltimateParent(u) ;
            int ultiPar_v = findUltimateParent(v) ;
            if(ultiPar_u == ultiPar_v) return ;
            // Check whose rank is more
            if(rank[ultiPar_u] < rank[ultiPar_v]){
                // No change in rank bcz smaller one is attched to larger one
                parent[ultiPar_u] = ultiPar_v ;
            }
            else if(rank[ultiPar_u] > rank[ultiPar_v]){
                parent[ultiPar_v] = ultiPar_u ;
            }
            // Both are same
            // Attaching v to u 
            else{
                parent[ultiPar_v] = ultiPar_u ;
                rank[ultiPar_u] ++ ;
            }
        }

        void unionBySize(int u , int v){
            int ultiPar_u = findUltimateParent(u) ;
            int ultiPar_v = findUltimateParent(v) ;
            if(ultiPar_u == ultiPar_v) return ;
            if(size[ultiPar_u] < size[ultiPar_v]){
                parent[ultiPar_u] = ultiPar_v ;
                size[ultiPar_v] += size[ultiPar_u] ;
            }
            else if(size[ultiPar_u] > size[ultiPar_v]){
                parent[ultiPar_v] = ultiPar_u ;
                size[ultiPar_u] += size[ultiPar_v] ;
            }
            else{
                parent[ultiPar_v] = ultiPar_u ;
                size[ultiPar_u] += size[ultiPar_v] ;
            }
        }
} ;
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int limit) {
       int n = arr.size() ;
        priority_queue<pair<int,int>> pq ;
       for(int i=0;i<arr.size();i++){
        pq.push({arr[i],i});
       }     
           DisjointSet ds(n) ;
       while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        if(abs(pq.top().first - it.first)<=limit)ds.unionBySize(it.second,pq.top().second);
       }
       vector<int>ans(n);
       unordered_map<int,vector<int>>mp;
       for(int i=0;i<n;i++){
        mp[ds.findUltimateParent(i)].push_back(i);
       }
       for(auto it:mp){
        auto vec=it.second;
        sort(vec.begin(),vec.end()); // ,yaha index sort kare jaise 0,1,2 index 
        vector<int>temp;
        for(auto t:vec)temp.push_back(arr[t]);//e;ement push kar diye
       
        sort(temp.begin(),temp.end()); // 153 se 135 kar diya
        int i=0;
        for(auto ind:vec){
            ans[ind]=temp[i++];
        }
       }
       return ans;
    }
};




// deko union kab kare ,if ultimate parent are same ,
// yaha swapping kab hogi , if first element is less than another ,and first element-another element <=limit
// if this is the case then we swapp them and move forward

// means if(helper(nums[i],nums[j],limit))swap else not



// brute force - using two loops ,
