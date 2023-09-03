int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if(obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1)
        {
            return 0;
        }

        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));

        return helper(obstacleGrid, 0, 0, dp);
    }

    int helper(vector<vector<int>>& grid, int x, int y, vector<vector<int>> &dp)
    {
        if(x >= grid.size() || y >= grid[0].size())
        {
            return 0;
        }

        if(x == grid.size() - 1 && y == grid[0].size() - 1)
        {
            return 1;

        }

        if(dp[x][y] != -1)
        {
            return dp[x][y];
        }

        if(grid[x][y] == 1)
        {
            return dp[x][y] = 0;
        }

        return dp[x][y] = helper(grid, x+1, y, dp) + helper(grid, x, y+1, dp);
    }
// Tabulation and Space Optimized Code:

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if(obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1 || obstacleGrid[0][0] == 1)
        {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, -1);

        // Tabulation

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[j] = 0;
                }

                else if(i == 0 && j == 0)
                {
                    dp[j] = 1;
                }
                
                else
                {
                    int r = 0;
                    int d = 0;

                    if(i > 0)
                    {
                        d = dp[j];
                    } 

                    if(j > 0)
                    {
                        r = dp[j-1];
                    }
                    dp[j] = r + d;
                }
            }
        }

        return dp[n-1];
    }
