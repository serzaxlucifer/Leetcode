int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(nums.begin(), nums.end());
        int count = 1;
        int size = nums.size();
        if(size == 0)
        {
            return 0;
        }
        int maxCount = 1;

        for(int i = 0; i < size-1; i++)
        {
            if(nums[i] == nums[i+1]-1)
            {
                count++;
                maxCount = maxCount < count ? count : maxCount;
            }
            else if(nums[i] == nums[i+1])
            {
                continue;
            }
            else
            {
                count = 1;
            }
        }

        return maxCount;
    }
