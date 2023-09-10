// Go back to Coin Change I and see the second recursive construct we used previously that utilizes a for loop in the recursion and offers a much better memoized algorithm.
// Why can't we use that here? If you use that (trying drawing its tree), it will generate duplicate combinations and count them.
// For example: 1, 2, 1, 1 AND 2, 1, 1, 1 will be counted twice. Thus, indexing parameter needs to be involved to avoid this for happening.
// So we can use this classical approach OR we can modify the FOR loop.


// Memoization:

int change(int amount, vector<int>& coins) 
    {
        // MEMOIZATION! 
        
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return noOfWays(coins, dp, amount, coins.size()-1);
    }

    int noOfWays(vector<int>& coins, vector<vector<int>> &dp, int amount, int index)
    {
        if(amount == 0)
        {
            return 1;
        }

        if(index < 0)
        {
            return 0;
        }

        if(dp[index][amount] != -1)
        {
            return dp[index][amount];
        }

        int notTake = noOfWays(coins, dp, amount, index-1);
        int take = 0;

        if(coins[index] <= amount)
        {
            take = noOfWays(coins, dp, amount-coins[index], index);
        }

        return dp[index][amount] = take+notTake;
    }

