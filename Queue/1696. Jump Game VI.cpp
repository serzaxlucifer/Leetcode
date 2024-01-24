int maxResult(vector<int>& nums, int k) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        vector<int> dp(nums.size(), INT_MIN);
        deque<int> q{0};

        dp[0] = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            if(q.front() < i - k)
            {
                q.pop_front();
            }
            dp[i] = nums[i] + dp[q.front()];

            while(!q.empty() && dp[q.back()] <= dp[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }

        return dp.back();
    }
