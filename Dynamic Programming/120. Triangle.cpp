// Recursive: (TLE)

int minimumTotal(vector<vector<int>>& triangle) 
    {
        // Recursive
        return helper(triangle, 0, 0);

    }

    int helper(vector<vector<int>>& triangle, int level, int index)
    {
        if(level >= triangle.size())
        {
            return 0;
        }

        return triangle[level][index] + min(helper(triangle, level + 1, index), helper(triangle, level + 1, index + 1));
    }

// Memoization:

int minimumTotal(vector<vector<int>>& triangle) 
    {
        // Recursive
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));
        return helper(triangle, 0, 0, dp);

    }

    int helper(vector<vector<int>>& triangle, int level, int index, vector<vector<int>> &dp)
    {
        if(level >= triangle.size())
        {
            return 0;
        }

        if(dp[level][index] != -1)
        {
            return dp[level][index];
        }

        return dp[level][index] = triangle[level][index] + min(helper(triangle, level + 1, index, dp), helper(triangle, level + 1, index + 1, dp));
    }

// Tabulation:

int minimumTotal(vector<vector<int>>& triangle) 
    {
        // TABULATION

        vector<int> dp(triangle.size(), -1);
        int size = triangle.size();

        dp[0] = triangle[0][0];

        for(int i = size - 1; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {

                if(i == size - 1)
                {
                    dp[j] = triangle[i][j];
                }

                else
                {
                    dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
                }
            }
        }

        return dp[0];
    }
