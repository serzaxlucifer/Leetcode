/*
    The logic here is that: If a single element is before mid, then first element of duplicate pair will be odd index and
    second will be at even index. If the single element is after mid, first element will be at even index and second at odd index.
*/
int singleNonDuplicate(vector<int>& nums) 
    {
        int size = nums.size();
        int start = 0;
        int end = size-1;
        int mid = (start + end) >> 1;

        while(start < end)
        {
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                start = mid + 1;
            else
                end = mid;
            mid = (start + end) >> 1;
        }

        return nums[start];
    }
