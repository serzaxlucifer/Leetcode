// Memoization

class Solution 
{
    public:
    string s1;
    string s2;

    int longestCommonSubsequence(string text1, string text2) 
    {
        vector<vector<int>> dp (text1.length(), vector<int>(text2.length(), -1));
        s1 = text1;
        s2 = text2;

        return util(text1.length()-1, text2.length()-1, dp);
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

class Solution 
{
    public:

    int longestCommonSubsequence(string text1, string text2) 
    {
        vector<vector<int>> dp (text1.length(), vector<int>(text2.length(), 0));
        dp[0][0] = text1[0] == text2[0];
        
        for(int i = 1; i < text2.length(); i++)
        {
            if(text1[0] == text2[i])
            {
                dp[0][i] = 1;
            }
            else
            {
                dp[0][i] = dp[0][i-1];
            }
        }

        for(int i = 1; i < text1.length(); i++)
        {
            if(text1[i] == text2[0])
            {
                dp[i][0] = 1;
            }
            else
            {
                dp[i][0] = dp[i-1][0];
            }
        }

        for(int i = 1; i < text1.length(); i++)
        {
            for(int j = 1; j < text2.length(); j++)
            {
                if(text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[text1.length()-1][text2.length()-1];
    }


};

//or

class Solution 
{
    public:

    int longestCommonSubsequence(string text1, string text2) 
    {
        vector<vector<int>> dp (text1.length()+1, vector<int>(text2.length()+1, 0));
        dp[0][0] = text1[0] == text2[0];
        
        for(int i = 0; i < text2.length()+1; i++)
        {
            dp[0][i] = 0;
        }

        for(int i = 0; i < text1.length()+1; i++)
        {
            dp[i][0] = 0;
        }

        for(int i = 1; i <= text1.length(); i++)
        {
            for(int j = 1; j <= text2.length(); j++)
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

        return dp[text1.length()][text2.length()];
    }


};
