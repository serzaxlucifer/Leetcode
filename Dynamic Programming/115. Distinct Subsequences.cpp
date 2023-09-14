// Memoization:

int numDistinct(string s, string t) 
    {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return util(s, t, s.length() - 1, t.length() - 1, dp);
    }

    int util(string& s, string& t, int i1, int i2, vector<vector<int>>& dp)
    {
        if(i2 < 0)
        {
            return 1;
        }

        if(i1 < 0)
        {
            return 0;
        }

        if(dp[i1][i2] != -1)
        {
            return dp[i1][i2];
        }

        if(s[i1] == t[i2])
        {
            return dp[i1][i2] = util(s, t, i1 - 1, i2 - 1, dp) + util(s, t, i1 - 1, i2, dp);
        }
        else
        {
            return dp[i1][i2] = util(s, t, i1 - 1, i2, dp);
        }
    }

// Tabulation:

    int numDistinct(string s, string t) 
    {
        vector<vector<unsigned int>> dp(s.length()+1, vector<unsigned int>(t.length()+1, 0));
        dp[0][0] = 1;

        for(int i = 1; i <= s.length(); i++)
        {
            dp[i][0] = 1;
            for(int j = 1; j <= t.length(); j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[s.length()][t.length()];
    }
