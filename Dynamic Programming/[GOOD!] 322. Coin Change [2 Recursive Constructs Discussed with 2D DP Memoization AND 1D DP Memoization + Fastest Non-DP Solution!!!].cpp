// RECURSIVE CONSTRUCT 1
// An initial thinking will lead you to figure out something like this:

// Memoization

int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = coinUtil(coins, amount, coins.size() - 1, dp);

        return ans == 1e9 ? -1 : ans;
    }

    int coinUtil(vector<int>& coins, int amount, int index, vector<vector<int>>& dp)
    {
        if(index == 0)
        {
            if(amount % coins[0] == 0)
            {
                return amount / coins[0];
            }

            else
            {
                return 1e9;
            }
        }

        if(dp[index][amount] != -1)
        {
            return dp[index][amount];
        }

        int notTake = coinUtil(coins, amount, index - 1, dp);
        int take = 1e9;                                         // a better substitute than INT_MAX to avoid overflow.

        if(coins[index] <= amount)
        {
            take = 1 + coinUtil(coins, amount - coins[index], index, dp);
        }

        return dp[index][amount] = min(take, notTake);
    }
// We'll improve this construct shortly but first, let's talk about its tabulated version.

// Tabulation:

int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, -1);
        

        for(int i = 0; i <= amount; i++)
        {
            if(i % coins[0] == 0)
            {
                dp[i] = i / coins[0];
            }

            else
            {
                dp[i] = 1e9;
            }
        }

        for(int ind = 1; ind < coins.size(); ind++)
        {
            vector<int> newdp(amount + 1, -1);
            for(int target = 0; target <= amount; target++)
            {
                int notTake = dp[target];
                int take = 1e9;

                if(coins[ind] <= target)
                {
                    take = 1 + newdp[target - coins[ind]];     // notice this! we're using newdp as supply is infinite!
                }
                
                newdp[target] = min(notTake, take);
            }
            dp = newdp;
        }

        return dp[amount] == 1e9 ? -1 : dp[amount];

    }

// RECURSIVE CONSTRUCT 2
// Now this apparently can be further optimized as per Leetcode's official Solution where we're using a 1d array to memoize!
//  As the supply is infinite, we're construcing our recursive function in a for loop based structure and trying to remove the index parameter in definition of the function.

// If the recursive utility function doesn't require an index parameter it will only have one paramter to memoize. Thus reducing the space needs massively.
// We can remove the use of index SINCE supply is infinite.

// Consider this code: (without Dynamic Programming):
    int coinChange(vector<int>& coins, int amount) 
    {
        return coinUtil(coins, amount);
    }

    int coinUtil(vector<int>& coins, int amount) 
    {
        if(amount == 0)
        {
            return 0;
        }

        if(amount < 0)
        {
            return -1;
        }
      
        int minTracker = INT_MAX;

        for(int coin: coins)
        {
            int count = coinUtil(coins, amount - coin);

            if(count == -1)
            {
                continue;
            }
            minTracker = min(minTracker, count + 1);
        }

        return minTracker == INT_MAX ? -1 : minTracker;
    }

// Digest this code!

// Memoization:

int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, -2);
        return coinUtil(coins, amount, dp);
    }

    int coinUtil(vector<int>& coins, int amount, vector<int> &dp) 
    {
        if(amount == 0)
        {
            return 0;
        }

        if(amount < 0)
        {
            return -1;
        }

        if(dp[amount] != -2)
        {
            return dp[amount];
        }

        int minTracker = INT_MAX;

        for(int coin: coins)
        {
            int count = coinUtil(coins, amount - coin, dp);

            if(count == -1)
            {
                continue;
            }
            minTracker = min(minTracker, count + 1);
        }

        return dp[amount] = minTracker == INT_MAX ? -1 : minTracker;
    }

// See the beauty of this code!

// Now let us try to tabulate it.

int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, 1e9);
        

        dp[0] = 0;

        for(int i = 1; i <= amount; i++)
        {
            for(int coin : coins)
            {
                if(i < coin)
                {
                    continue;
                }
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }

        return dp[amount] == 1e9 ? -1 : dp[amount];

    }

// I know this is tough. I know.

// NOW Lets discuss a third approach!! This one yields the BEST runtime on Leetcode, drastically faster than DP and doesn't utilize DP.

int coinChange(vector<int>& coins, int amount) 
    {
        
        if(amount & 1)
        {
            int i = 0;
            for(i = 0; i < coins.size(); i++)
            {
                if(coins[i] & 1)
                {
                    break;
                }
            }

            if(i == coins.size())
            {
                return -1;
            }
        }

        sort(coins.begin(), coins.end());

        int best = amount/coins.back();
        int worst = amount/coins.front();

        for(int i = best; i <= worst; i++)
        {
            if(check(coins, coins.size() - 1, i, amount))
            {
                return i;
            }
        }

        return -1;

    }

    // Devise an algorithm to check. Also, coins is sorted.
    bool check(vector<int>& coins, int index, int count, int target)
    {
        long sum = (long)coins[index]*count;

        if(sum < target)
        {
            return false;       // more coins are needed!
        }

        if(sum == target)
        {
            return true;
        }

        if(sum > target)        // use other coins for some count... and re-verify
        {
            if(index == 0)
            {
                return false;
            }
            
            for(int i = count; i > 0; i--)     // start removing coins one by one or the other way around as shown here.
            {
                long takeAway = target - (long)coins[index]*(count - i);
                if(takeAway < 0)
                {
                    break;
                }
                if(check(coins, index - 1, i, takeAway))
                {
                    return true;
                }
            }
        }

        return false;
    }
