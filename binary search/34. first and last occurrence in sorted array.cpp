// my solution : runtime - 0ms & LeetCode 34

vector<int> searchRange(vector<int>& nums, int target) {
        int fo = -1;
        int lo = -1;

        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end - start)/2;

        while(start <= end)
        {
            if(nums[mid] == target)
            {
                fo = lo = mid;
                for(int i = mid - 1; i >= 0 && nums[i] == nums[mid]; i--)
                {
                    fo = i;
                }
                for(int i = mid + 1; i < nums.size() && nums[i] == nums[mid]; i++)
                {
                    lo = i;
                }
                break;
            }
            if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }

        return {fo, lo};
    }

// other solution:

vector<int> searchRange(vector<int>& nums, int target) {
        int fo = -1;
        int lo = -1;

        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end - start)/2;

        // find first occurence!
        while(start <= end)
        {
            if(nums[mid] == target)
            {
                if(mid == 0 || nums[mid-1] != nums[mid])
                {
                    fo = mid;
                    break;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else if(nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }

        start = 0;
        end = nums.size()-1;
        mid = start + (end - start)/2;

        // find last occurence!
        while(start <= end)
        {
            if(nums[mid] == target)
            {
                if(mid == nums.size()-1 || nums[mid+1] != nums[mid])
                {
                    lo = mid;
                    break;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else if(nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }

        return {fo, lo};
    }
