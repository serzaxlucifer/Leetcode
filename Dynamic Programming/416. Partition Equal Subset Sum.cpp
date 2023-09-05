// Recursion (Plain)
bool canPartition(vector<int>& nums)   // gives TLE!
    {
        //vector<vector<int>> dp (nums.size(), )

        return partitionUtil(nums, 0, 0, 0);
    }

    bool partitionUtil(vector<int>& nums, int index, int sum1, int sum2)
    {
        if(index == nums.size())
        {
            return sum1 == sum2;
        }

        return partitionUtil(nums, index + 1, sum1, sum2 + nums[index]) || partitionUtil(nums, index + 1, sum1 + nums[index], sum2);

    }


// Memoization: What to memorize? How to form the DP storage algorithm?

bool canPartition(vector<int>& nums) 
    {
        int totSum=0;
    
        for(int i = 0; i < nums.size(); i++)
        {
            totSum += nums[i];
        }
    
        if (totSum % 2 == 1) 
            return false;

        vector<vector<int>> dp (nums.size(), vector<int> (totSum + 1, -1));

        return partitionUtil(nums, 0, 0, 0, dp);
    }

    bool partitionUtil(vector<int>& nums, int index, int sum1, int sum2, vector<vector<int>> &dp)
    {
        if(index == nums.size())
        {
            return sum1 == sum2;
        }

        if(dp[index][sum1] != -1)
        {
            return dp[index][sum1] == 1;
        }

        return dp[index][sum1] = partitionUtil(nums, index + 1, sum1, sum2 + nums[index], dp) || partitionUtil(nums, index + 1, sum1 + nums[index], sum2, dp);

    }

// Reduced Space consumption:

bool canPartition(vector<int>& nums) 
    {
        int totSum = 0;
    
        for(int i = 0; i < nums.size(); i++)
        {
            totSum += nums[i];
        }
    
        if (totSum % 2 == 1) 
            return false;

        vector<vector<int>> dp (nums.size(), vector<int> (totSum / 2 + 1, -1));

        return partitionUtil(nums, 0, totSum / 2, dp);
    }

    bool partitionUtil(vector<int>& nums, int index, int sum, vector<vector<int>> &dp)
    {
        if(sum == 0)
        {
            return true;
        }

        if(index >= nums.size())
        {
            return false;
        }

        if(dp[index][sum] != -1)
        {
            return dp[index][sum];
        }

        bool take = false, notTake = false;

        notTake = partitionUtil(nums, index + 1, sum, dp);

        if(sum >= nums[index])
        {
            take = partitionUtil(nums, index + 1, sum - nums[index], dp);
        }

        return dp[index][sum] = take || notTake;

    }


// Tabulation: 



// Space Optimized Tabulation:



