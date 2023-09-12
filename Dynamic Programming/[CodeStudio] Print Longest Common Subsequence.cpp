// Memoization:

    string util(int i1, int i2, vector<vector<string>>& dp, string& s1, string& s2)
    {
        if(i1 < 0 || i2 < 0)
        {
            return "";
        }

        if(dp[i1][i2] != "0")
        {
            return dp[i1][i2];
        }

        if(s1[i1] == s2[i2])
        {
            return s1[i1] + util(i1 - 1, i2 - 1, dp, s1, s2);
        }

		string a1 = util(i1 - 1, i2, dp, s1, s2);
		string a2 = util(i1, i2 - 1, dp, s1, s2);

        return dp[i1][i2] = (a1.length() >= a2.length() ? a1 : a2);

    }

string findLCS(int n, int m,string &s1, string &s2)
{
	vector<vector<string>> dp (s1.length(), vector<string>(s2.length(), "0"));
	string res = util(s1.length()-1, s2.length()-1, dp, s1, s2);

	reverse(res.begin(), res.end());

    return res;
}

// Tabulation:

string findLCS(int n, int m,string &s1, string &s2)
{
	vector<vector<int>> dp (s1.length()+1, vector<int>(s2.length()+1, 0));
        
        for(int i = 0; i < s2.length()+1; i++)
        {
            dp[0][i] = 0;
        }

        for(int i = 0; i < s1.length()+1; i++)
        {
            dp[i][0] = 0;
        }

		string answerBRUH;

        for(int i = 1; i <= s1.length(); i++)
        {
            for(int j = 1; j <= s2.length(); j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

		// The DP array is computed.

		while(n > 0 && m > 0)
		{
			if(s1[n-1] == s2[m-1])
			{
				answerBRUH += s1[n-1];
				n--, m--;
			}
			else
			{
				if (dp[n - 1][m] > dp[n][m - 1])
                n--;
            	else
                m--;
			}
		}

		reverse(answerBRUH.begin(), answerBRUH.end());

        return answerBRUH;
	
}
