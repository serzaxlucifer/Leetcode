// my initial soln:

int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;

        for(int i : nums)
        {
            if(i)
            {
                count++;
            }
            else
            {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        maxCount = max(maxCount, count);

        return maxCount;

    }

