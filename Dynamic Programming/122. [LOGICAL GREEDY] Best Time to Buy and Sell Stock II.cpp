// GREEDY:

    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            profit += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;        // Now, think why this works! HINT: Make a graph of days(x) vs. stock price(y) and see if this works or not!
        }

        return profit;
    }



