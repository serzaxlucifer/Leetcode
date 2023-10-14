// Memoization:

int lengthOfLIS(vector<int>& nums) 
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));

        return util(nums, -1, 0, dp);
    }

    int util(vector<int>& nums, int prev, int cur, vector<vector<int>>& dp)
    {
        if(cur == nums.size())
        {
            return 0;
        }

        if(dp[prev+1][cur] != -1)
        {
            return dp[prev+1][cur];
        }

        // can you take?
        int take = 0;
        int notTake = util(nums, prev, cur + 1, dp);

        if(prev == -1 || nums[cur] > nums[prev])
        {
            take = 1 + util(nums, cur, cur + 1, dp);
        }

        return dp[prev+1][cur] = max(take, notTake);
    }

// Tabulation:

int lengthOfLIS(vector<int>& nums) 
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            for(int j = i - 1; j >= -1; j--)
            {
                int take = 0;
                int notTake = dp[j+1][i+1];

                if(j == -1 || nums[i] > nums[j])
                {
                    take = 1 + dp[i+1][i+1];    // you stored in +1 state!
                }

                dp[j+1][i] = max(take, notTake);
            }
        }

        return dp[0][0];
    }

// PRINTING THE LIS:



// Optimization using Binary Search:
int lengthOfLIS(vector<int>& nums) 
    {
        // I SWEAR TO GOD!!!!

        vector<int> aux;
        aux.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > aux.back())
            {
                aux.push_back(nums[i]);
            }
            else
            {
                // employ binary search
                auto index = lower_bound(aux.begin(), aux.end(), nums[i]) - aux.begin();
                aux[index] = nums[i];
            }
        }

        return aux.size();
    }
