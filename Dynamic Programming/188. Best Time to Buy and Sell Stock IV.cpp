int maxProfit(int k, vector<int>& prices) 
    {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return util(prices, 0, 1, k, dp);
    }

    int util(vector<int>& prices, int cur, int buy, int cap, vector<vector<vector<int>>>& dp)    // cap will restrict transactions to 2. buy = 0 means you are already holding a stock and 1 means you can buy.
    {
        if(cap == 0)
        {
            return 0;
        }
        if(cur == prices.size())
        {
            return 0;
        }
        if(dp[cur][buy][cap] != -1)
        {
            return dp[cur][buy][cap];
        }

        int profit = 0;
        if(buy)
        {
            profit = max(- prices[cur] + util(prices, cur + 1, 0, cap, dp), 0 + util(prices, cur + 1, 1, cap, dp));
        }
        else
        {
            profit = max(prices[cur] + util(prices, cur + 1, 1, cap - 1, dp), 0 + util(prices, cur + 1, 0, cap, dp));
        }

        return dp[cur][buy][cap] = profit;
    }

// Tabulated:

int maxProfit(int k, vector<int>& prices) // runtime: beats 83%
    {
        vector<vector<int>> dp(2, vector<int>(k + 1, 0));      // constant space optimized (equivalent to 6 variables in a stricter sense)

        for(int i = prices.size()-1; i >= 0; i--)
        {
            for(int buy = 0; buy < 2; buy++)
            {
                for(int cap = 1; cap <= k; cap++)
                {
                    if(buy)
                    {
                        dp[buy][cap] = max(- prices[i] + dp[0][cap], dp[1][cap]);
                    }
                    else
                    {
                        dp[buy][cap] = max(prices[i] + dp[1][cap-1], dp[0][cap]);
                    }
                }
            }
        }

        return dp[1][k];
    }

// MORE:

// See the skip karo solution
