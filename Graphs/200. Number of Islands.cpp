    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        int numIsland = 0;
        queue<pair<int,int>> BFS;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')  // if unexplored land
                {
                    numIsland++;

                    BFS.push({i, j});
                    grid[i][j] = 'a';
                    while(!BFS.empty())
                    {
                        int a = BFS.front().first, b = BFS.front().second;
                        BFS.pop();

                        if(a - 1 >= 0 && grid[a-1][b] == '1')
                        {
                            grid[a-1][b] = 'a';
                            BFS.push({a-1, b});
                        }
                        if(b - 1 >= 0 && grid[a][b-1] == '1')
                        {
                            grid[a][b-1] = 'a';
                            BFS.push({a, b-1});
                        }
                        if(a + 1 < m && grid[a+1][b] == '1')
                        {
                            grid[a+1][b] = 'a';
                            BFS.push({a+1, b});
                        }
                        if(b + 1 < n && grid[a][b+1] == '1')
                        {
                            grid[a][b+1] = 'a';
                            BFS.push({a, b+1});
                        }
                    }
                }
            }
        }

        return numIsland;
    }
