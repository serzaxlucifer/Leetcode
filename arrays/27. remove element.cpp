int removeElement(vector<int>& nums, int val) {
        int insertIndex = 0;
        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            if(nums[i] != val)
            {
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }

        return insertIndex;
    }
