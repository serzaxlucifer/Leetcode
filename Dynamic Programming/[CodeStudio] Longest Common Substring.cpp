// Tabulation:

int lcs(string &str1, string &str2)
{
    vector<int> dp(str2.length() + 1, 0);
    int ans = 0;

    for(int i = 1; i < str1.length()+1; i++)
    {
        for(int j = str2.length(); j > 0; j--)
        {
            if(str1[i-1] == str2[j-1])
            {
                int maxx = 1 + dp[j-1];
                dp[j] = maxx;
                ans = max(ans, maxx);
            }
            else
            {
                dp[j] = 0;
            }
        }

    }

    return ans;
}

// Please NOTE that it can BE SOLVED in LINEAR TIME using Generalized Suffix Trees which will be discussed later in Strings section.
