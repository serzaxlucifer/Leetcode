// This is where 'strong' reasoning is needed.

// You see, you can make two cases out of this: We know if we really have to choose then only one out of first and last house can be chosen
// THUS, in one case assume first house doesn't exist and in second case, assume that last house doesn't exist. And simply, the maximum of both is the answer.

int rob_helper(vector<int>& nums, int start, int end) 
    {
        // Tabulation Solution.

        int prev1 = nums[end];
        int prev2 = 0;

        for(int i = end - 1; i > start - 1; i--)
        {
            int aux = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = aux;
        }

        return prev1;
        
    }

    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        return max(rob_helper(nums, 0, nums.size() - 2), rob_helper(nums, 1, nums.size() - 1));
    }
