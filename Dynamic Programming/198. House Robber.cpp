// Recurisve:

int rob(vector<int>& nums) 
    {
        // Recursive Solution.
        
        return helper(nums, 0);
        
    }

    int helper(vector<int>& nums, int index)
    {
        if(index > nums.size()-1)
        {
            return 0;
        }
        if(index == nums.size()-1)
        {
            return nums[index];
        }

        int pick = nums[index] + helper(nums, index + 2);
        int nonPick = helper(nums, index + 1);

        return max(pick, nonPick);
    }

// Memoization:

int rob(vector<int>& nums) 
    {
        // Recursive + Memoization Solution.

        vector<int> dp(nums.size() + 1, -1);
        
        return helper(nums, 0, dp);
        
    }

    int helper(vector<int>& nums, int index, vector<int>& dp)
    {
        if(index > nums.size()-1)
        {
            return 0;
        }
        if(index == nums.size()-1)
        {
            return nums[index];
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }

        int pick = nums[index] + helper(nums, index + 2, dp);
        int nonPick = helper(nums, index + 1, dp);

        return dp[index] = max(pick, nonPick);
    }   

// Tabulation:

int rob(vector<int>& nums) 
    {
        // Tabulation Solution.

        vector<int> dp(nums.size() + 1, -1);
        dp[nums.size()-1] = nums[nums.size()-1];
        dp[nums.size()] = 0;

        for(int i = nums.size() - 2; i > -1; i--)
        {
            int pick, nonPick;

            nonPick = dp[i+1];
            pick = dp[i+2] + nums[i];

            dp[i] = max(pick, nonPick);
        }

        return dp[0];
        
    }

// Space Optimization:

int rob(vector<int>& nums) 
    {
        // Tabulation Solution.

        int prev1 = nums[nums.size()-1];
        int prev2 = 0;

        for(int i = nums.size() - 2; i > -1; i--)
        {
            int aux = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = aux;
        }

        return prev1;
        
    }

