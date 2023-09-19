int maxProfit(vector<int>& prices) 
    {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));

        return util(prices, 0, 1, 2, dp);
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

// Let's Tabulate it:

int maxProfit(vector<int>& prices) 
    {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i = prices.size()-1; i >= 0; i--)
        {
            for(int buy = 0; buy < 2; buy++)
            {
                for(int cap = 1; cap < 3; cap++)
                {
                    if(buy)
                    {
                        dp[i][buy][cap] = max(- prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    }
                    else
                    {
                        dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }

// Space Optimization:

int maxProfit(vector<int>& prices) // runtime: beats 83%
    {
        vector<vector<int>> dp(2, vector<int>(3, 0));      // constant space optimized (equivalent to 6 variables in a stricter sense)

        for(int i = prices.size()-1; i >= 0; i--)
        {
            for(int buy = 0; buy < 2; buy++)
            {
                for(int cap = 1; cap < 3; cap++)
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

        return dp[1][2];
    }


// Let's try to analyze what this code is doing in literal sense! Then we can employ some other tactics.
/*
    This code starts from the end and considers all possibilities and stores their results and back computes maximum values that can be achieved.
    At each step you know that if you didn't perform any transaction or 1 or 2, how much max profit you have in each case and we basically
    back propagate that to till entire array is covered to generate maxProfit for it.
*/

// But this can be modelled further down to a single loop traversal (no nested loop) and just 4 variables at its best! HOW?! Let's see!
// We can also explain the above codes in other words. On every day, we buy the share with the price as low as we can, and sell the share with price as high as we can. 
// For the second transaction, we integrate the profit of first transaction into the cost of the second buy, then the profit of the second sell will be the total profit of two transactions.


// Below code is courtesy of Leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/solutions/135704/detail-explanation-of-dp-solution/

// 2 pass: (JAVA)

public int maxProfit(int[] prices) {
        int n=prices.length, pass[] = new int[n], buy=Integer.MAX_VALUE, sell=0, prof=0, i;
        // Pass 1: Forward
        for(i=0; i<n; i++) {
            if(buy>prices[i]) buy=sell=prices[i];
            sell=Math.max(sell, prices[i]);
            pass[i]=prof=Math.max(prof, sell-buy);
        }

        // Pass 2: Reversed
        int res=pass[n-1];
        for(i=n-1, sell=prof=0, buy=Integer.MAX_VALUE; i>0; --i) {
            if(sell<prices[i]) sell=buy=prices[i];
            buy=Math.min(buy, prices[i]);
            res=Math.max(res, pass[i-1]+sell-buy);
        }
        return res;
    }

// 1 pass:

    int maxProfit(std::vector<int>& prices) 
    {
        int FirstTransactionCost = prices[0];
        int FirstTransactionProfit = 0;

        int mostMoneyInPockets = -prices[0];
        int profitFromTwoTransactions = 0;

        for(int currentPrice: prices) 
        {
            FirstTransactionCost = min(FirstTransactionCost, currentPrice);
            FirstTransactionProfit = max(FirstTransactionProfit, currentPrice - FirstTransactionCost);

            mostMoneyInPockets = max(mostMoneyInPockets, FirstTransactionProfit - currentPrice);
            profitFromTwoTransactions = max(profitFromTwoTransactions, mostMoneyInPockets + currentPrice);
        }

        return profitFromTwoTransactions;
    }
