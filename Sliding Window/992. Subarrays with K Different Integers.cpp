int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int count[20001] = {0};
        int left = 0;
        int middle = 0;
        int right = 0;
        int answer = 0;
        int size = nums.size();

        for(; right < size; right++)
        {
            if(++count[nums[right]] == 1)
            {
                if(--k < 0)
                {
                    count[nums[middle++]] = 0;
                    left = middle;
                }
            }

            if(k <= 0)
            {
                while(count[nums[middle]] > 1)
                {
                    --count[nums[middle++]];
                }
                answer += middle - left + 1;
            }
        }

        return answer;
    }
