// Same as KMP Pre-Processing

    string longestPrefix(string s) 
    {
        int j = 0;
        vector<int> dp(s.size());

        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == s[j])
            {
                dp[i] = ++j;
            }
            else if(j > 0)
            {
                j = dp[j - 1];
                --i;
            }
        }

        return s.substr(0, j);
    }
