int minimumEffortPath(vector<vector<int>>& heights) 
    {
        // dijkstra

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> DIJK;
        int xmax = heights.size(), ymax = heights[0].size();
        vector<vector<int>> DIST(xmax, vector<int>(ymax, 1e9));
        DIJK.push({0, 0 << 16 | 0}); DIST[0][0] = 0;

        int dirx[4] = {0, 1, -1, 0};
        int diry[4] = {1, 0, 0, -1};
        
        while(!DIJK.empty())
        {
            auto q = DIJK.top(); DIJK.pop();
            int y = q.second & 0xFFFF ;
            int x = q.second >> 16;
            int maxD = q.first;

            if(x == xmax - 1 && y == ymax - 1)
            {
                return maxD;
            }

            for(int i = 0; i < 4; i++)
            {
                int newx = x + dirx[i], newy = y + diry[i];
                if(newx >= 0 && newx < xmax && newy >= 0 && newy < ymax) //&& newx != x && newy != y)
                {
                    int newEffort = max(abs(heights[x][y] - heights[newx][newy]), maxD);

                    if(newEffort < DIST[newx][newy])
                    {
                        DIST[newx][newy] = newEffort;
                        DIJK.push({newEffort, newx << 16 | newy});
                    }
                }
            }

        }

        return 0;
    }
