// Can we compute this in single traversal of the input vector? Sure, we can.

int maxProfit(vector<int>& prices) 
    {
        // Can we do in single traversal?

        int maxProfit = 0;
        int consideredStock = prices[0];

        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < consideredStock)
            {
                consideredStock = prices[i];
            }

            int profit = prices[i] - consideredStock;

            if(profit > maxProfit)
            {
                maxProfit = profit;
            }
        }


        return maxProfit;
    }

