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

// bad soln:

int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int maxCount = 0;
        int curNum;
        int count = 1;
        unordered_set<int> hashSet;

        for(int i : nums)
        {
            hashSet.insert(i);
        }

        for(int i : nums)
        {
            curNum = i;
            if(hashSet.find(i-1) == hashSet.end())
            {
                count = 1;
                while(hashSet.find(curNum+1)!= hashSet.end())
                {
                    count++;
                    curNum++;
                }
                maxCount = count <= maxCount ? maxCount : count;
            }
        }

        return maxCount;
    }
