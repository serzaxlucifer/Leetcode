// My Solution (1st): Runtime: 3ms [88%] | LEETCODE 33

int search(vector<int>& nums, int target) 
{
       
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;

        while(start <= end)
        {
            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[mid] > nums[end])
            {
                // rotation needs accounting.
                if(target > nums[mid] || target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else
            {
                if(target > nums[mid] && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            mid = start + (end - start)/2;
        }

        return -1;
}


// 0ms Solution
int search(vector<int>& nums, int target) 
{
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            //two scenarios
            //pivot element is larger than first element in array
            //pivot element is smaller than first element in array
            else if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            else {
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
}

