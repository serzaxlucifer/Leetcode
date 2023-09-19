// I think we are very well versed with stocks by now. We will discuss advanced and complex solutions here.
// SEE: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/75928/share-my-dp-solution-by-state-machine-thinking/

int maxProfit(vector<int>& prices)
{
		if (prices.size() <= 1) 
      return 0;
  
		vector<int> s0(prices.size(), 0);
		vector<int> s1(prices.size(), 0);
		vector<int> s2(prices.size(), 0);
  
		s1[0] = -prices[0];    // buying
		s0[0] = 0;      // rest
		s2[0] = INT_MIN;       // selling!
  // cant go to s1 directly from s2. s2 -> s0 -> s1
  
		for (int i = 1; i < prices.size(); i++) 
    {
			s0[i] = max(s0[i - 1], s2[i - 1]);
			s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
			s2[i] = s1[i - 1] + prices[i];
		}
  
		return max(s0[prices.size() - 1], s2[prices.size() - 1]);
}

// or, rewriting:

int maxProfit(vector<int>& prices) 
    {
        // A recursive solution is easy to build. Let's start on a tabulated version right
        // from the start!

        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(3, 0));
        // for each I have three things to do -> 0. buy, 1. rest or 2. sell

        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = INT_MIN;

        for(int i = 1; i < size; i++)
        {
            dp[i][0] = max(dp[i-1][1] - prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][2]);
            dp[i][2] = dp[i-1][0] + prices[i];
        }

        return max(dp[size-1][1], dp[size-1][2]);
    }

int maxProfit(vector<int>& prices) 
{
    int sold = 0, hold = INT_MIN, rest = 0;
    for (int i=0; i<prices.size(); ++i)
    {
        int prvSold = sold;
        sold = hold + prices[i];
        hold = max(hold, rest-prices[i]);
        rest = max(rest, prvSold);
    }
    return max(sold, rest);
}

int maxProfit(vector<int>& prices) 
    {
        // A recursive solution is easy to build. Let's start on a tabulated version right
        // from the start!

        int size = prices.size();

        int buy = -prices[0];      
        int rest = 0;               
        int sold = INT_MIN;         

        for(int i = 1; i < size; i++)
        {
            int prevSold = sold;
            sold = buy + prices[i];
            buy = max(rest - prices[i], buy);
            rest = max(rest, prevSold);
        }

        return max(rest, sold);
    }
