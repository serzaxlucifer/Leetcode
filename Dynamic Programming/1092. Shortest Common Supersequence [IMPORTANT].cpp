// This is a good question to develop skills in DP on Strings!
// Let's get this DONE~!

// Our first approach, let's take it as decomposition to already known questions and then using their result to derive our result.
// See, what can we use?! LCS, LPS? Something should work!

// YES, We can compute the LCS string and then EASILY form the supersequence!
// Let's do that before we try to attempt anything else. Both memoized and tabulated ofc ;)

// you can do this on your own, now that I think of it!

// Let's now construct a specific solution to produce the solution to this problem!

string shortestCommonSupersequence(string str1, string str2) 
    {
        vector<vector<string>> dp(str1.length(), vector<string>(str2.length(), "0"));

        return util(str1, str2, str1.length()-1, str2.length()-1, dp);
    }

    string util(string& s1, string& s2, int i1, int i2, vector<vector<string>>& dp)
    {
        if(i1 < 0)
        {
            return s2.substr(0, i2+1);
        }

        if(i2 < 0)
        {
            return s1.substr(0, i1+1);
        }

        if(dp[i1][i2] != "0")
        {
            return dp[i1][i2];
        }

        if(s1[i1] == s2[i2])
        {
            return dp[i1][i2] = util(s1, s2, i1-1, i2-1, dp) + s1[i1];
        }
        else
        {
            string a = util(s1, s2, i1-1, i2, dp);
            string b = util(s1, s2, i1, i2-1, dp);

            if(a.length() > b.length())
            {
                return dp[i1][i2] = b + s2[i2];
            }
            else
            {
                return dp[i1][i2] = a + s1[i1];
            }
        }
    }

// This gives memory limit exceeded! Let's try using TABULATION to reduce space complexity to O(N). Let's try using some other ways too! AHHHH, MEMORY!!!!!!
// btw today is a day i'm celebrating beauty in simple things today! :) wishing a nice day to whoever reads this (lol, I know noone will!)


string shortestCommonSupersequence(string str1, string str2) 
    {
        vector<string> dp(str2.length()+1,  "");

        for(int i = 0; i <= str2.length(); i++)
        {
            dp[i] = str2.substr(0, i);
        }

        for(int i = 1; i <= str1.length(); i++)
        {
            vector<string> ndp(str2.length()+1,  "");
            ndp[0] = str1.substr(0, i);

            for(int j = 1; j <= str2.length(); j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    ndp[j] = dp[j-1] + str1[i-1];
                }
                else
                {
                    string a = dp[j];
                    string b = ndp[j-1];

                    if(a.length() > b.length())
                    {
                        ndp[j] = b + str2[j-1];
                    }
                    else
                    {
                        ndp[j] = a + str1[i-1];
                    }
                }
            }

            dp = ndp;
        }

        return dp[str2.length()];
    }

// This solution takes a memory of 735MB to process and 2s to run. Obviously, both the previous approaches were absolutely trash for ONE reason which isn't related to logic
// but how the DP grid was used to compute. 

// Why is the solution bad?
// We're processing such big strings so many times. Copying and deleting in big arrays.
// NEVER approach like this. VECTOR<VECTOR<STRING>> FOR DP? NEVER! Look at that! It generated 735MB of data. Too complex to process!!

// HAD IT BEEN integral values, it'd be 95% faster! Can we use an integer dp (all operations are exponentially faster) and then using
// that integral grid, generate the supersequence? YES, we can! Just like in LCS. The grid will help in picking which indexes to choose!

// Let's quickly tabulate it.


string shortestCommonSupersequence(string str1, string str2) 
    {
        vector<vector<int>> dp(str1.length()+1, vector<int>(str2.length()+1, 0));

        for(int i = 0; i <= str2.length(); i++)
        {
            dp[0][i] = i;
        }

        for(int i = 1; i <= str1.length(); i++)
        {
            dp[i][0] = i;

            for(int j = 1; j <= str2.length(); j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // dp[str1.length()][str2.length()] now has the length of our supersequence.

        string ans = "";
        int n = str1.length(), m = str2.length();

        while(n > 0 && m > 0)
		{
			if(str1[n-1] == str2[m-1])
			{
				ans += str1[n-1];
				n--, m--;
			}
			else
			{
				if (dp[n - 1][m] > dp[n][m - 1])
                {
                    ans += str2[m-1];
                    m--;
                }
                
                else
                {
                    ans += str1[n - 1];
                    n--;
                }
			}
		}

        if(n != 0)
        {
            string s = str1.substr(0, n);
            reverse(s.begin(), s.end());
            ans += s;
        }
        if(m != 0)
        {
            string s = str2.substr(0, m);
            reverse(s.begin(), s.end());
            ans += s;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }    // runtime: 17ms or 0.017s (!!!)
