// This seems tough :(
// But atleast we're aware that we're to employ Dynamic Programming. 
// So, let's start with building a recursive solution and then deploy Memoization on it.

int minDistance(string word1, string word2) 
    {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m, vector<int> (n, -1));

        return util(word1, word2, m-1, n-1, dp);
    }

    int util(string& s1, string& s2, int i1, int i2, vector<vector<int>>& dp)
    {
        if(i1 < 0)
        {
            return i2+1;
        }
        if(i2 < 0)
        {
            return i1+1;
        }
        if(dp[i1][i2] != -1)
        {
            return dp[i1][i2];
        }

        if(s1[i1] == s2[i2])
        {
            return dp[i1][i2] = util(s1, s2, i1 - 1, i2 - 1, dp);
        }
        else
        {
            return dp[i1][i2] = min({util(s1, s2, i1 - 1, i2 - 1, dp), util(s1, s2, i1, i2 - 1, dp), util(s1, s2, i1 - 1, i2, dp)}) + 1;
        }
    }

// Tabulation:

int minDistance(string word1, string word2) 
    {
        int m = word1.length();
        int n = word2.length();

        int dp[m + 1][n + 1];

        for(int i = 0;i <= m; i++) 
        {
            dp[i][0] = i;
        }

        for(int i = 0; i <= n; i++) 
        {
            dp[0][i] = i;
        }

        for(int i = 1; i <=m; i++)
        {
            for(int j = 1;j <= n; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                                    // replace        // delete      // insert
                }
            }
        }

        return dp[m][n];
    }



