// Initial Sliding Window Approach:

int longestOnes(vector<int>& nums, int k) 
    {
        int start = 0;
        int ones = 0;
        int zeros = 0;
        int answer = 0;

        int size = nums.size();

        for(int end = 0; end < size; end++)
        {
            if(!nums[end])
            {
                zeros++;
                while(zeros > k)
                {
                    if(!nums[start])
                        zeros--;
                    start++, ones--;
                }
            }
            ones++;
            answer = max(answer, ones);
        }

        return answer;
    }

// Further Optimizing writing style: (better in memory requirements, same time wise)

    int longestOnes(vector<int>& nums, int k) 
    {
        int i = 0, j;
        for (j = 0; j < nums.size(); ++j) 
        {
            if (nums[j] == 0)
                k--;
            if (k < 0 && nums[i++] == 0) 
                k++;
        }
        return j - i;
    }
