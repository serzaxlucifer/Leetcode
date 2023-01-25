int missingNumber(vector<int>& nums) 
    {
        // MATH
        int size = nums.size();

        int sum = 0;
        for(int i : nums)
        {
            sum+=i;
        }
        return (size*(size+1)/2-sum);
    }
