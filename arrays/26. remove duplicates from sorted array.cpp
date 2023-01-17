int removeDuplicates(vector<int>& nums) {
        int insertIndex = 1;
        int size = nums.size();

        for(int i = 1; i < size; i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }

        return insertIndex;
    }
