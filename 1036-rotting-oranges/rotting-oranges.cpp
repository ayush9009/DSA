class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // bfs kuki min,maximum kaha , hai, to ek karke posisble directionn lo,
        //  aur visited bhi lena hai, taki same jagah dubare na ja,
        // vaise visted ki need ni hai, kuki 3 conditons uske bsais pai ,bas
        // maark karni ek loop

        int dx[] = {0, 1, 0, -1}; // to traverse in 4 directions from each node
        int dy[] = {1, 0, -1, 0};

        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>>
            q; // storing indexing of each cell,only rotten, one so
        // we traverse only rotten once adjcaent to make their neigbhours rotten
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push(
                        {i,
                         j}); // basically first cell dek ra hoon , ki vo rotten
                    // mile taki bas usey gadi shuru ho jaye, faltu cells
                    // queue mai push karne ka ki mltb ni hai
                }
            }
        }

        int minMinutes = 0;

        // deko at particular time,Every minute, any fresh orange that is
        // 4-directionally adjacent to a rotten orange becomes rotten.

        // mtlb 3 rotten oranges hai grid mai, currelty ,means at t=0
        //  to t=1 , pai in sab kai ajdacent oranges , rotten mark ho jange,
        //    eg:
        // 012
        // 012
        // 211
        // intially at t=0 ki state
        // t=1 kya hoga , (0,2) vala apne adjancet rotten mark karega  queue
        // mmpush then (1,2) apne ajdance rotten mark karege queue m push the
        // (0,0) apen ajdancet rotten mark karega.

        // ye ek level isme itne hi rotten mark ho sake tha,
        // now next level/next minute , ab jo rotten mark kiye thai unke adjcent
        // rotten mark honge , aise har minute , sab rotten mark hote jange

        while (!q.empty()) {
            int sze = q.size();
            
            while (sze--) {
                auto it = q.front();
                int curHorizontalDist = it.first;
                int curVerticalDist = it.second;

                q.pop();

                for (int i = 0; i < 4; i++) {
                    int x = curHorizontalDist + dx[i];
                    int y = curVerticalDist + dy[i];

                    if (x >= n || y >= m || x < 0 || y < 0 || grid[x][y] == 0)
                        continue; // to hanlde out of bound

                    if (grid[x][y] == 1) {
                        // jo rootne ni usey rottne mark kiya queue mai dal
                        // diya.
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }

           if(!q.empty()) minMinutes++; // minute shuru hogyi ,is min mai cur node k adj rotten mark honge ye isliye kuki supppose karo
        //    22
        //    22
        //    to answer 0 ana chaiye par if !q.empty ye na lagao to 1 return hoga
        //    jo ki glt hai , time nikalna kitne time mai sab rotten
        // to is case mai to already sab rootten hai to 0 time
        }

        // if still any fresh oragne present, means it's impossible to make that
        // rotten
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return minMinutes;
    }
};