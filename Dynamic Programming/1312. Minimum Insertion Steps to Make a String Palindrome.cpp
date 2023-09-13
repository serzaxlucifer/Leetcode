// One approach is to compute the length of longest palindromic subsequence (already discussed). and simply return string.length() - lps; (pretty obvious after doing LPS).

// But let's construct a recursive structure specially for computing this number. :)

int minInsertions(string s) 
    {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));

        return util(s, 0, s.length()-1, dp);
    }

    int util(string& s, int i, int j, vector<vector<int>>& dp)
    {
        if(i > j)
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(s[i] == s[j])
        {
            return dp[i][j] = util(s, i + 1, j - 1, dp);
        }
        else
        {
            return dp[i][j] = 1 + min(util(s, i, j - 1, dp), util(s, i + 1, j, dp));
        }
    }

// Tabulation:

int minInsertions(string s) 
    {
        vector<int> dp(s.length(), 0);

        for(int i = s.length() - 1; i >= 0; i--)
        {
            vector<int> ndp(s.length(), 0);
            for(int j = i + 1; j < s.length(); j++)
            {
                if(s[i] == s[j])
                {
                    ndp[j] = dp[j-1];
                }
                else
                {
                    ndp[j] = 1 + min(dp[j], ndp[j-1]);
                }
            }

            dp = ndp;
        }
        

        return dp[s.length()-1];
    }
