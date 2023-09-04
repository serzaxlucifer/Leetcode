// Code for Memoization:

int helper(vector<vector<int>> &grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp)
{
    if(j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size())
    {
        return -1e9;
    }

    if(i == grid.size()-1)
    {
        if(j1 == j2)
        {
            return grid[i][j1];
        }
        return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }

    int maxi = INT_MIN;

    for(int a = -1; a < 2; a++)
    {
        for(int b = -1; b < 2; b++)
        {
            int value = 0;

            if(j1 == j2)
            {
                value = grid[i][j1] + helper(grid, i + 1, j1 + a, j2 + b, dp);
            }

            else
            {
                value = grid[i][j1] + grid[i][j2] + helper(grid, i + 1, j1 + a, j2 + b, dp);
            }

            maxi = max(maxi, value);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));

    return helper(grid, 0, 0, c - 1, dp);
}

// Iterative (Tabulation)

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Initializing the 'prev_dp' vector.
    vector<vector<int>> prev_dp(c, vector<int>(c));

    // Running a loop from 0 to 'r'.
    for (int row = 0; row < r; row++) {
        // Initializing a 'current_dp' vector.
        vector<vector<int>> current_dp(c, vector<int>(c));
        // Running a loop from 0 to 'min(c, row + 1)'.
        for (int c1 = 0; c1 < min(c, row + 1); c1++) {
            // Running a loop from 'max(0, c - 1 - row)' to 'c'.
            for (int c2 = max(0, c - 1 - row); c2 < c; c2++) {
                // Initializing a variable 'prev_max'.
                int prev_max = 0;
                for (int offset1 = max(0, c1 - 1); offset1 <= min(c - 1, c1 + 1); offset1++) {
                    for (int offset2 = max(0, c2 - 1); offset2 <= min(c - 1, c2 + 1); offset2++) {
                        // Updating the variable 'prev_max'.
                        prev_max = max(prev_max, prev_dp[offset1][offset2]);
                    }
                }
                // Case when both are in same row.
                if (c1 == c2) {
                    current_dp[c1][c2] = prev_max + grid[row][c1];
                } else {
                    current_dp[c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
                }
            }
        }
        prev_dp = current_dp;
    }
    int res = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            // Updating the variable 'res' with max possible answer.
            res = max(res, prev_dp[i][j]);
        }
    }
    return res;
}
