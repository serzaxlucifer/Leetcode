// my first implementation:

int findMin(vector<int>& nums) {
        int size = nums.size()-1;
        if(size == 1)                         // handled specially since this causes error if follows general algorithm
        {
            return min(nums[0], nums[1]);
        }
        int end = nums.size()-1;
        int start = 0;

        int mid = (start + end) >> 1;

        while(start <= end)
        {
            if(nums[mid] <= nums[size])
            {
                // this part ain't in rotated. Need to go to its beginning.
                if(mid == 0)
                {
                    return nums[0];
                }
                if(nums[mid] < nums[mid-1])
                {
                    return nums[mid];
                }
                if(nums[mid] >= nums[mid-1])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                start = mid + 1;
            }
            mid = (start + end) >> 1;
        }

        return nums[0];
    }
// Shortest:

int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return nums[lo];
    
    }

// Optimization: Logic of Binary Search remains same but we try to form better if-else conditions to process the searching. It comes down to this:

int findMin(vector<int>& nums) {
        int size = nums.size()-1;
        int end = size;
        int minEle = INT_MAX;
        int start = 0;

        int mid;

        while(start <= end)
        {
            if(nums[start] < nums[end])                 // the magic optimization happens here! It eliminates a lot of computation!
            {
                // current sequence is sorted w/o rotation.
                if(minEle > nums[start])
                {
                    minEle = nums[start];
                }
                break;
            }
            mid = (start + end) >> 1;
            if(minEle > nums[mid]) minEle = nums[mid];
            if(nums[mid] < nums[start])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return minEle;
    }
