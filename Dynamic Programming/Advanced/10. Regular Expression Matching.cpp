    bool isMatch(string s, string p) 
    {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));

        dp[0][0] = true;

        for(int i = 0; i < p.length(); i++)
        {
            if(p[i] == '*' && dp[0][i - 1])
            {
                dp[0][i+1] = true;
            }
        }

        for(int i = 0; i < s.length(); i++)
        {
            for(int j = 0; j < p.length(); j++)
            {
                if(s[i] == p[j] || p[j] == '.')
                {
                    dp[i+1][j+1] = dp[i][j];
                }
                if(p[j] == '*')
                {
                    if(p[j-1] != s[i] && p[j-1] != '.')
                    {
                        dp[i+1][j+1] = dp[i+1][j-1];
                    }
                    else
                    {
                        dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1]);
                    }
                }
            }
        }

        return dp[s.length()][p.length()];
    }
