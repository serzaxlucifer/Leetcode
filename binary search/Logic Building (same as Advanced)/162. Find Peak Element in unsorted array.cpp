//  The key is to follow the greater element.

int findPeakElement(vector<int>& nums) {
        // Binary Ssearch -- Finding Peaks (an important application)
        int start = 0;
        int size = nums.size();

        if(size==1)
        {
            return 0;
        }

        int end = size-1;
        int mid = (start+end) >> 1;

        while(start < end)
        {
            if (mid == 0)
            return nums[0] >= nums[1] ? 0 : 1;

            if (mid == size - 1)
            return nums[size - 1] >= nums[size - 2] ? size - 1 : size - 2;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            {
                return mid;
            }

            if(nums[mid] < nums[mid+1]) // follow greater element!
            {
                start = mid + 1;
            }
            else                        // follow the greater element.
            {
                end = mid - 1;
            }
            mid = (start+end) >> 1;
        }

        return start;
    }
