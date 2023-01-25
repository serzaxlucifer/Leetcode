int missingNumber(vector<int>& nums) 
    {
        int x = 0;
        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            x ^= i;
            x ^= nums[i];
        }

        return x^size;
    }

