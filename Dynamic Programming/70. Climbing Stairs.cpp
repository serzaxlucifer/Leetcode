// NOTICE HOW THIS PROBLEM IS EXACTLY SIMILAR TO FIBONACCI NUMBER PROBLEM!!

// DP-based Solution [Memoization]

int climbStairs(int n) 
    {
        vector<int> dp(n + 1, -1);
        return counter(n, dp);
    }

    int counter(int n, vector<int>& dp)
    {
    //base case
        if(n < 0)
            return 0;
    
        if(n == 0)
            return 1;
    
        if(dp[n] != -1)
        {
            return dp[n];
        }

        return dp[n] = counter(n - 1, dp) + counter(n - 2, dp);
    }

// DP Space Optimized with Tabulation

int climbStairs(int n) 
    {
        int prev2 = 1, prev = 1;

        for(int i = 2; i <= n; i++)
        {
            int cur = prev2 + prev;
            prev2 = prev;
            prev = cur;
        }

        return prev;
    }

// Best solution: O(log(n)) BINARY EXPONENTIATION


