// recursive brute force

int uniquePaths(int m, int n) {
        return countPaths(0, 0, m, n);
    }

    int countPaths(int i, int j, int m, int n)
    {
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        if(i >= m || j >= n)
        {
            return 0;
        }
        return countPaths(i+1,j,m,n) + countPaths(i, j+1,m,n);
    }

// DP Solution:

int uniquePaths(int m, int n) {
        vector<int> t(n, -1);
        vector<vector<int>> dp(m, t);
        return countPaths(0, 0, m, n, dp);
    }

    int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp)
    {
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        if(i >= m || j >= n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j] = countPaths(i+1,j,m,n, dp) + countPaths(i, j+1,m,n, dp);
    }

// Combinatorics

int uniquePaths(int m, int n) {
        long answer = 1;

        for(int i = 1; i <= m-1; i++)
        {
            answer = (answer*(n-1+i))/i;
        }

        return (int)answer;
    }
// aahhhhh!



