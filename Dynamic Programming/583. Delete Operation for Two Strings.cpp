// One Obvious solution is to FIND the LCS of the two strings and 
// return (word1.length() - LCS) + (word2.length() - LCS);

// But as usual, let's define functions catering to this specific problem!

// MEMOIZATION:

int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));

        return util(word1, word2, word1.length() - 1, word2.length() - 1, dp);
    }

    int util(string& word1, string& word2, int i1, int i2, vector<vector<int>>& dp)
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

        if(word1[i1] == word2[i2])
        {
            return dp[i1][i2] = util(word1, word2, i1 - 1, i2 - 1, dp);
        }
        else
        {
            return dp[i1][i2] = 1 + min(util(word1, word2, i1 - 1, i2, dp), util(word1, word2, i1, i2 - 1, dp));
        }
    }

// TABULATION:

int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));

        for(int i = 0; i <= word2.length(); i++)
        {
            dp[0][i] = i;
        }

        for(int i = 1; i <= word1.length(); i++)
        {
            dp[i][0] = i;
            for(int j = 1; j <= word2.length(); j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[word1.length()][word2.length()];
    }
