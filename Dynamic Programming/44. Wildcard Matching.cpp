/*
    DYNAMIC PROGRAMMING!
*/

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        vector<vector<int>> dp(s.length(), vector<int> (p.length(), -1));
        return matchingUtil(s, p, s.length() - 1, p.length() - 1, dp);
    }

    int matchingUtil(string& s, string& t, int i1, int i2, vector<vector<int>>& dp)
    {

        if(i1 < 0 && i2 < 0)
        {
            return true;
        }

        if(i2 < 0)
        {
            return false;
        }
        if(i1 < 0)
        {
            return isAllStars(t, i2);
        }


        if(dp[i1][i2] != -1)
        {
            return dp[i1][i2];
        }
        
        if(s[i1] == t[i2] || t[i2] == '?')
        {
            return dp[i1][i2] = matchingUtil(s, t, i1 - 1, i2 - 1, dp);
        }

        else if(t[i2] == '*')
        {
            return dp[i1][i2] = matchingUtil(s, t, i1 - 1, i2, dp) || matchingUtil(s, t, i1, i2 - 1, dp);
        }

        else
        {
            return dp[i1][i2] = false;
        }
    }

    bool isAllStars(string& s, int i2)
    {
        for(int i = 0; i <= i2; i++)
        {
            if(s[i] != '*')
            {
                return false;
            }
        }
        return true;
    }
};


// TABULATION:    // runtime: beats 95%, 86% in memory

bool isMatch(string s, string p) 
    {
        int m = p.size();
        int n = s.size();
        bool dp[n + 1][m + 1];

        memset(dp, false, sizeof(dp));
        dp[0][0] = true;

        for(int i = 1; i <= p.length(); i++)            // look at my memoization code.
        {
            if(p[i - 1] == '*')
            {
                dp[0][i] = dp[0][i - 1];
            }
        }

        for(int i1 = 1; i1 <= s.length(); i1++)
        {
            for(int i2 = 1; i2 <= p.length(); i2++)
            {
                if(s[i1 - 1] == p[i2 - 1] || p[i2 - 1] == '?')
                {
                    dp[i1][i2] = dp[i1 - 1][i2 - 1];
                }

                else if(p[i2 - 1] == '*')
                {
                    dp[i1][i2] = dp[i1 - 1][i2] || dp[i1][i2 - 1];
                }

                else
                {
                    dp[i1][i2] = false;
                }
            }
        }

        return dp[s.length()][p.length()];
    }
