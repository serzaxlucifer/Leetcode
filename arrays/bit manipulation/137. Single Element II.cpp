// Bit Manipulation Solution:

int singleNumber(vector<int>& nums) {
        int ones = 0;       // to keep track which numbers are occuring only once in the array.
        int twos = 0;       // to keep track which numbers are occuring twice in the array.

        for(int i : nums)
        {
            ones = (ones^i) & (~twos);
            twos = (twos^i) & (~ones);
        }

        return ones;
    }

// Bit Counting Solution:

int singleNumber(vector<int>& nums) {
        int answer = 0;

        for(int j = 0; j < 32; j++)
        {
            int sum = 0;
            for(int i : nums)
            {
                if((i >> j) & 1)
                {
                    sum++;
                }
            }

            sum %= 3;
            if(sum!=0)
            {
                answer |= (sum << j);
            }
            
        }
        return answer;
    }

