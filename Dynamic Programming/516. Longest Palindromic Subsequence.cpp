// Memoization:

// Machine:   WHAT. IS. LOVE.?

class Solution {
    public:
    string s1;
    string s2;

    int longestPalindromeSubseq(string s) 
    {
        vector<vector<int>> dp (s.length(), vector<int>(s.length(), -1));
        s1 = s;
        reverse(s.begin(), s.end());
        s2 = s;

        return util(s.length()-1, s.length()-1, dp);
    }

    int util(int i1, int i2, vector<vector<int>>& dp)
    {
        if(i1 < 0 || i2 < 0)
        {
            return 0;
        }

        if(dp[i1][i2] != -1)
        {
            return dp[i1][i2];
        }

        if(s1[i1] == s2[i2])
        {
            return 1 + util(i1 - 1, i2 - 1, dp);
        }

        return dp[i1][i2] = max(util(i1 - 1, i2, dp), util(i1, i2 - 1, dp));

    }
};

// Tabulation:

int longestPalindromeSubseq(string s) 
    {
        vector<vector<int>> dp (s.length()+1, vector<int>(s.length()+1, 0));
        string text1 = s;
        reverse(s.begin(), s.end());
        string text2 = s;

        for(int i = 1; i <= s.length(); i++)
        {
            for(int j = 1; j <= s.length(); j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[s.length()][s.length()];
    }

// Now, let's discuss a better way to model this situation! (Without using LCS and reverse concept.)
// When we see palindrome, two pointer tactics should pop in your mind! What if we combine that with recursive DP?

int longestPalindromeSubseq(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> dp (s.length(), vector<int>(s.length(), -1));

        return util(s, 0, s.length() - 1, dp);
    }

    int util(string& s, int i1, int i2, vector<vector<int>>& dp)
    {
        if(i1 > i2)
        {
            return 0;
        }

        if(i1 == i2)
        {
            return 1;
        }

        if(dp[i1][i2] != -1)
        {
            return dp[i1][i2];
        }

        if(s[i1] == s[i2])
        {
            return dp[i1][i2] = 2 + util(s, i1 + 1, i2 - 1, dp);
        }
        else
        {
            return dp[i1][i2] = max(util(s, i1 + 1, i2, dp), util(s, i1, i2 - 1, dp));
        }

    }

// Tabulation:

int longestPalindromeSubseq(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> dp (s.length(), vector<int>(s.length(), 0));
    
        for(int i = s.length() - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for(int j = i + 1; j < s.length(); j++)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][s.length()-1];
    }
