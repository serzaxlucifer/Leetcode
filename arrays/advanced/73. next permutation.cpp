    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)
        {
            return;
        }

        int r1 = size-2;
        while(r1 > 0 && nums[r1] >= nums[r1+1])
        {
            r1--;
        }

        int r2 = size-1;
        while(r2 > r1 && nums[r2] <= nums[r1])
        {
            r2--;
        }

        int temp = nums[r2];
        nums[r2] = nums[r1];
        nums[r1] = temp;

        if(r2 == 0)
        {
            reverse(nums, r1);
            return;
        }

        reverse(nums, r1+1);
    }

    void reverse(vector<int>& nums, int start)
    {
        int end = nums.size()-1;
        while(start < end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

// next: OPTIMIZED

    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int swapPoint;
        for(int i = size-2; i >= 0; i--)
        {
            if(nums[i+1] >= nums[i])
            {
                swapPoint = i;
                break;
            }
        }
        if(swapPoint < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for(int i = size - 1; i > swapPoint; i--)
            {
                if(nums[swapPoint] < nums[i])
                {
                    swap(nums[swapPoint], nums[i]);
                    reverse(nums.begin()+swapPoint +1, nums.end());
                    break;
                }
            }
        }
    }

// Video Explanation (decision tree, similar logic): https://youtu.be/LuLCLgMElus
