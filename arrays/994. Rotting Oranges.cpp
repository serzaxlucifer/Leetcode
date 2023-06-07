// BFS Employment: 95% runtime

int orangesRotting(vector<vector<int>>& grid) {
        // BFS Employed Solution utilizing a normal queue.

        int oranges = 0;
        int rottenOranges = 0;
        int cols = grid[0].size();
        int rows = grid.size();
        int neighbourX, neighbourY;
        int X, Y;

        queue<pair<int, int>> queue;            // of rotten oranges

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j])
                {
                    oranges++;
                    if(grid[i][j] == 2)
                    {
                        rottenOranges++;
                        queue.push({i, j});
                    }
                }
            }
        }

        int minutes = 0;

        // Matrix Traversal Variables
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};        // [row, col] format    // can also use standard dx = [0, 1, -1, 0] and dy = [1, 0, 0, -1] format.

        while(!queue.empty())
        {
            int frontierSize = queue.size();         // represents the oranges to consider in this minute.

            while(frontierSize--)
            {
                // check all the neigbouring oranges and rot them hahaha~

                X = queue.front().first;
                Y = queue.front().second;
                queue.pop();

                for(int i = 0; i < 4; i++)
                {
                    neighbourX = X + directions[i][0];
                    neighbourY = Y + directions[i][1];

                    if(neighbourX >= 0 && neighbourX < rows && neighbourY >= 0 && neighbourY < cols && grid[neighbourX][neighbourY] == 1)
                    {
                        // rot it!
                        rottenOranges++;
                        grid[neighbourX][neighbourY] = 2;
                        queue.push({neighbourX, neighbourY});
                    }
                }
            }
            if(!queue.empty())
            {
                minutes++;
            }
        }

        if(rottenOranges == oranges)
        {
            return minutes;
        }

        return -1;
    }

//-------------------------------------------------------------------

