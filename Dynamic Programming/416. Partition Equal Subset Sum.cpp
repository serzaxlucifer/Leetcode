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

bool canPartition(vector<int>& nums)             // best runtime among all solutions! (Recursion proves more fruitful as it avoids filling the complete DP table if 'true' is concluded at earlier stages.)
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


// Space Optimized Tabulation:


bool canPartition(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int totSum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            totSum += nums[i];
        }
        
        if (totSum % 2)
            return false;
        
        vector<bool> dp(totSum/2 + 1, 0);
        
        dp[0] = true;
        if(nums[0] <= totSum/2)
        {
            dp[nums[0]] = true;
        }
        
        for(int i = 1; i < nums.size(); i++)
        {
            vector<bool> newdp (totSum /2+1, 0); newdp[0] = true;
            for(int j = 1; j <= totSum / 2 ; j++)
            {
                bool notTake = dp[j];
                bool take = false;
                
                if(nums[i] <= j)
                {
                    take = dp[j - nums[i]];
                }
                
                newdp[j] = take || notTake;
            }
            
            dp = newdp;
        }
        
        return dp[totSum/2];
    
    }
